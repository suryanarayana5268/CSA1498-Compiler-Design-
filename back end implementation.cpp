#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;
int registerCount = 0;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

void generateAssembly(char op, int operand1, int operand2) {
    printf("LOAD R%d, %d\n", registerCount, operand1);
    printf("%s R%d, %d\n", (op == '+') ? "ADD" : 
                            (op == '-') ? "SUB" : 
                            (op == '*') ? "MUL" : "DIV", 
                            registerCount, operand2);
    push(registerCount);
    registerCount++;
}

void evaluatePostfix(char* expression) {
    int i = 0, operand1, operand2;
    
    printf("Generated Assembly Code:\n");
    
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        } else {
            operand2 = pop();
            operand1 = pop();
            generateAssembly(expression[i], operand1, operand2);
        }
        i++;
    }

    printf("STORE RESULT, R%d\n", pop());
}

int main() {
    char postfix[MAX];
    
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    
    evaluatePostfix(postfix);
    
    return 0;
}

