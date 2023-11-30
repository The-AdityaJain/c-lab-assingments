#include<stdio.h>
#include<stdlib.h>

struct node{
	int prn;
	char name[20];
	struct node *next;
};
void create(struct node *head){
	struct node *temp,*curr;
	temp=head;
	int y;
	do{
	curr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the prn in node : ");
	scanf("%d",&curr->prn);
	printf("Enter the name in node : ");
	scanf("%s",&curr->name);
	curr->next=NULL;
	temp->next=curr;
	temp=curr;
	printf("node added\n");
	printf("Do you want to continue? Press 1 to continue :");
	scanf("%d",&y);
	
	}while(y==1);

}
void display(struct node *head){
	struct node *temp,*curr;
	if(head->next==NULL){
		printf("List is empty\n");
	}
	else{
		curr=head->next;
        printf("PRN\tName\tPosition\n");
        while(curr!=NULL){
            if(curr==head->next){
                printf("%d\t%s\tPresident\n",curr->prn,curr->name);
                curr=curr->next;
            }
            else if(curr->next!=NULL){
                printf("%d\t%s\tMember\n",curr->prn,curr->name);
                curr=curr->next;
            }
            else{
                printf("%d\t%s\tSecretory\n",curr->prn,curr->name);	
                curr=curr->next;      
            }
        }
    }


}
int length(struct node *head){
	int i = 0;
	struct node *temp,*curr;
	if(head->next==NULL){
		printf("List is empty");
	}
	else{
	curr=head->next;
	}
	while(curr!=NULL){
	i++;
	curr=curr->next;
	}
	return i;
}
void insertbypos(struct node *head){
    
    struct node *temp,*curr,*nnode;
	int i = 1,pos;
	curr=head->next;
	nnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the prn in node : ");
	scanf("%d",&nnode->prn);
	printf("Enter the name in node : ");
	scanf("%s",&nnode->name);
	printf("Enter the position of new node to be inserted : ");
	scanf("%d",&pos);
    if(pos>(length(head)+1)){
        printf("error!!!");
    }
    while(curr!=NULL && i<pos){
        curr=curr->next;
        i++;
    }
    nnode->next=curr->next;
    curr->next=nnode;

}
int main(){
	struct node *head;
	head=(struct node *)malloc(sizeof(struct node));
	head->next=NULL;
	create(head);
	display(head);
	int size=length(head);
	printf("Length is %d\n",size);
    insertbypos(head);
    
    display(head);
}
