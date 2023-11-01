#include<stdio.h>
#include<stdlib.h>
//this is a user defined data type whose name is node so further anywhere node is mentioned it means the data type like int,float,etc.
struct node{
	int data;
    //this variable is used to store base address of next node(which is user defined data type) which can be anywhere in memory
	struct node *nextAddress;
}; 
int main(){
	/* this is declaration of pointer of datatype node i.e it will have address of node datatype where
    head is the first node of link list which does not have any data but it has address of next node of linked list */
    struct node *head;

    // this will allocate memory for struct and will return base address which is stored in pointer head
    head=(struct node *)malloc(sizeof(struct node)); 

    // here we are storing null in nextAddress variable of node because for now there is no next node present so it should have null
	head->nextAddress=NULL;

	create(head);
	display(head);

}
void create(struct node *head){
	struct node *temp,*currentNode;

    // here the base address value of head returned through malloc i.e first node of sll is given to pointer temp
	temp=head;

	int y;
	do{
    /* here memory for new node which maybe allocated at any place in memory and it will 
    the base address of the new node is stored so that we can link it with the previous node 
    or save it in nextAddress space of previous node */ 
    /*everytime the loop is iterated, everytime there is new memory allocated for new node of list with its unique base address*/
	currentNode = (struct node*)malloc(sizeof(struct node));

    // here we have store value in the data variable of node
	printf("Enter the data in node : ");
	scanf("%d",&currentNode->data);

    // here we are storing null value in nextAddress variable of currentNode because there is again no new node present as of now
	currentNode->nextAddress=NULL;

    // here we are storing base address of currentNode/new node into the nextNode variable of previous(head in first iteration) node 
    temp->nextAddress=currentNode;
    
    //here we are updating the head variable with base address of currentNode
    // so that it can be used to save base address of next node of linked list in nextAddress 
	temp=currentNode;

	printf("node added\n");
	printf("Do you want to continue?\nPress 1 to continue ");
	scanf("%d",&y);
	
	}while(y==1);

}
void display(struct node *head){
	struct node *temp,*currentNode;
	
    //here we will first stored base address of head i.e first node of linked list in currentNode
    currentNode=head;
    while(currentNode!=NULL){
            printf("%d\n",currentNode->data);
            currentNode=currentNode->nextAddress;
    }

}