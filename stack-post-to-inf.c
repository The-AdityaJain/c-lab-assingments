#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
char stk[MAX][MAX];
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
void push1(char str[MAX]){
    if(isFull()){
    printf("stack is full");
    }
    else{
    top++;
    strcpy(stk[top],str);
    }
}
void pop1(char str[MAX]){
    if(isEmpty()){
    printf("stack is empty\n");
    }
    else{
    strcpy(str,stk[top]);
    top--;
    }
}

void post_inf(char post[MAX])
{
char s1[MAX] ,s2[MAX],s3[MAX],temp[MAX];
    for(int i=0;post[i]!='\0';i++){
        s1[0]=post[i];
        s1[1]='\0';
        if(isalpha(post[i])!=0)
            push1(s1);
        else{
            pop1(s2);
            pop1(s3);
            strcpy(temp,"(");
            strcat(temp,s3);
            strcat(temp,s1);
            strcat(temp,s2);
            strcat(temp,")");
            push1(temp);
        }
    }
char inf[MAX];
pop1(inf);
printf("\nthe infix expr is: %s",inf);
}

int main(){
    char inexp[MAX],postexp[MAX];
    printf("Enter the string : ");
    scanf("%s",postexp);
    post_inf(postexp);
    return 0;
}
