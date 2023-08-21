#include<stdio.h>

int i,j,k;

struct student{
	char name[10];
	int div;
	int rno;
	int cgpa;
};
void accept(struct student s[10],int n){
	for(i=0;i<n;i++){
		scanf("%s",&s[i].name);
	}
	for(i=0;i<n;i++){
			scanf("%d",&s[i].div);
		}
	for(i=0;i<n;i++){
			scanf("%d",&s[i].rno);
		}
	for(i=0;i<n;i++){
				scanf("%d",&s[i].cgpa);
			}

}
void display(struct student s[10],int n){
	for(i=0;i<n;i++){
		printf("%s\n",s[i].name);
	}
	for(i=0;i<n;i++){
			printf("%d\n",s[i].div);
		}
	for(i=0;i<n;i++){
			printf("%d\n",s[i].rno);
		}
	for(i=0;i<n;i++){
				printf("%d\n",&s[i].cgpa);
			}

}

int main(){
	struct student s[10];
	accept(struct student s[10],int n);
	display(struct student s[10],int n);
}
