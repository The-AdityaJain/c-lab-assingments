#include <stdio.h>
#include <ctype.h>

#define SIZE 50

int stack[SIZE];
int top = -1;

void pushval(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int popval() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;  // Assuming -1 as an error value
    }
    return stack[top--];
}

int calc(int a, int b, char op) {
    int ans;
    switch(op) {
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            ans = a / b;
            break;
        default:
            printf("Invalid operator\n");
            ans = 0;  // Assuming 0 as an error value
    }
    return ans;
}

void eval(char post[SIZE]) {
    int i, z, op1, op2, ans;

    for (i = 0; post[i] != '\0'; i++) {
        if (isalpha(post[i]) != 0) {
            printf("\nEnter value of %c: ", post[i]);
            scanf("%d", &z);
            pushval(z);
        } else {
            op1 = popval();
            op2 = popval();
            ans = calc(op1, op2, post[i]);
            pushval(ans);
        }
    }

    printf("\nEvaluation is: %d\n", stack[top]);
}

int main() {
    char postfixExpression[SIZE];

    printf("Enter postfix expression: ");
    scanf("%s", postfixExpression);

    eval(postfixExpression);

    return 0;
}
