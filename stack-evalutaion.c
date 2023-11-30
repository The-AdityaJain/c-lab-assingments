#include <stdio.h>
#include<ctype.h>


#define MAX 5
int top = -1;
int stk[MAX];


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
void push(int item){
	if(!isFull()){
		top=top+1;
		stk[top]=item;
	}
	else{
		printf("STACK IS FULL\n");
	}
}
int pop(){
        int temp;
        if(!isEmpty()){
		temp=stk[top];
		top=top-1;
		return temp;
	}
	else{
		printf("STACK IS EMPTY\n");
		return 0;
	}
}
int main(){
	int item;
	int choice;
    
	do{  
        	printf("\nPerform operations on the stack :");  
        	printf("\n1.Push the element\n2.Pop the element\n3.End");  
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
            			break;
        	}  
    	}while(choice!=3);  
    	int inexp[20],postexp[20];
    	printf("Enter the string : ");
    	scanf("%s",&postexp);
        eval(postexp);
        
        

    	
}
void eval(char post[MAX]){
     int op1,op2,ans,z;
    for(int i=0;post[i]!='\0';i++){
        
        if(isalpha(post[i])!=0) {
       
        printf("\nEnter value of %c",post[i]);
        scanf("%d",&z);
        push(z);
        }
        else{
        op1=pop();
        op2=pop();
        ans=calc(op1,op2,post[i]);
        push(ans);
        }
    } 
    printf("\nEvaluation is. ");
    printf("%d",stk[top]);
    
}
int calc(int a,int b,int op){
    int ans;
    switch(op){

        case '+':
        ans=a+b;
        break;
        case '-':
        ans-a-b;
        break;
        case '*':
        ans=a*b;
        break;
        case '/':
        ans = a / b;
        break;
        default:;

    }
    return(ans);
}


