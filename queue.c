#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int que[MAX];
int front,rear;
int front = -1;
int rear = -1;

int isFull(){
    if(rear==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if(front == rear){
        return 1;
    }
    else{
        return 0;
    }
}
void AddQ(int element){
    if(isFull()){
        printf("Queue is full");
    }
    else{
        rear = rear + 1;
        que[rear]=element;
    }
}

int DeleteQ(){
    int element;
    if(isEmpty()){
        printf("Queue is empty");
    }
    else{
        front = front + 1;
        element=que[front];
        return element;
    }
}
void display(){
    for(int i = 0;i <= rear;i++){
        printf("%d\t",que[i]);
    }
}

int main(){
    int item;
	int choice;
    
	while(choice!=4){
        	printf("\nPerform operations on the scheduler :");  
        	printf("\n1.Add job\n2.Delete job\n3.Display\n4.Exit");  
        	printf("\n\nEnter the choice : ");  
        	scanf("%d", &choice);  
        	switch (choice){  
        		case 1:  
        			printf("Enter JOB to be done : ");
        			scanf(" %d",&item);
            		AddQ(item);
            		break;  
        		case 2:  
            		item = DeleteQ();  
            	    printf("JOB complete is %d",item);
            		break;  
                case 3:
                    display();
                    break;
                case 4:
                    break;
        	}  
    }       
}
