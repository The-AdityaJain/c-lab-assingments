#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 20
char stk[MAX];
int top = -1;

int isFull() {
    if (top == MAX - 1) {
        return 1;
    }
    else {
       return 0;
    }
}
int isEmpty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}
void push(char item){
	if(!isFull()){
		top=top+1;
		stk[top]=item;
	}
	else{
		printf("STACK IS FULL\n");
	}
}
char pop(){
        char temp;
        if(!isEmpty()){
		temp=stk[top];
		top=top-1;
		return temp;
	}
	else{
		printf("STACK IS EMPTY\n");
		return '\0';
	}
}
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= top; ++i) {
        printf("%c ", stk[i]);
    }
    printf("\n");
}

int icp(char ch){
	if(ch=='+'||ch=='-'){
		return 1;
	}
	if(ch=='*'||ch=='/'){
		return 2;
	}
	if(ch=='^'){
		return 4;
	}
	if(ch=='('){
		return 5;
	}
	else{
		return 0;
	}
}
int isp(char ch){
	if(ch=='+'||ch=='-'){
		return 1;
	}
	if(ch=='*'||ch=='/'){
		return 2;
	}
	if(ch=='^'){
		return 3;
	}
	else{
		return 0;
	}
}
void in_post(char inexp[20]){
	char postexp[20];
	int k=0,i=0;
	char tkn=inexp[i];
	while(tkn!='\0'){
		if(isalpha(tkn)){
		postexp[k]=inexp[i];
		k++;
		}//if ends
		else{	//1 else
			if(tkn=='('){
				push('(');
			}	//if ends
			else {	//2 else
				if(tkn==')'){
					while((tkn=pop())!='('){   //while(tkn=pop()!='(')//!isEmpty() && stk[top]!='('
						postexp[k]=tkn;
						k++;
					}	//while ends
				}	//if ends
				else{	//3 else
					while(!isEmpty() && isp(stk[top]) >= icp(tkn)){
						postexp[k]=pop();
						k++;
					}	//while ends
                push(tkn);
				}	//3 else ends
			}	//2 else ends
		}	//1 else ends
		i++;
		tkn=inexp[i];
	}	//while ends
	while(!isEmpty()){
		postexp[k]=pop();
		k++;
	}
	postexp[k]='\0';
	printf("Expression = %s",postexp);
}

int main(){
	char item;
	int choice;
	char inexp[20],postexp[20];
	do{  
        	printf("\nPerform operations on the stack :");  
        	printf("\n1.Push the element\n2.Pop the element\n3.Infix to Postfix\n4.End\n");  
        	printf("\n\nEnter the choice : ");  
        	scanf("%d", &choice);  
        	switch (choice){  
        		case 1:  
        			printf("Enter item to push : ");
        			scanf(" %c",&item);
            			push(item);  
            			break;  
        		case 2:  
            			item = pop();  
            			printf("popped item is %c",item);
            			break;  
            		case 3:
				printf("Enter the string : ");
				scanf("%s",&inexp);
				in_post(inexp);
            			break;
        	}  
    	}while(choice!=4);  
    	
    	
}
