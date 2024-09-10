#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

char input[MAX];

void push(char c) {
    stack[++top] = c;
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

void displayStack() {
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\t");
}

void displayInput(int i) {
    printf("%s\n", input + i);
}


int checkReduction() {
    if (top >= 2) {
        if (stack[top] == 'E' && (stack[top-1] == '+' || stack[top-1] == '*') && stack[top-2] == 'E') {
            pop(); pop(); pop();
            push('E');
            return 1;
        }
    }

    if (top >= 2) {
        if (stack[top] == ')' && stack[top-1] == 'E' && stack[top-2] == '(') {
            pop(); pop(); pop(); 
            push('E');
            return 1;
        }
    }

    if (top >= 0) {
        if (stack[top] == 'i') {
            pop(); 
            push('E');
            return 1;
        }
    }

    return 0; 
}

int main() {
    printf("Enter the input string:\n");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0'; 

    printf("STACK\tINPUT\n");
    printf("-----\t-----\n");

    int i = 0;
    char currentSymbol[3];

    while (input[i] != '\0') {
        if (input[i] != ' ') {
            currentSymbol[0] = input[i];
            if (input[i + 1] == 'd') { 
                currentSymbol[1] = input[i + 1];
                currentSymbol[2] = '\0';
                push('i'); 
                i += 2;
            } else {
                push(input[i]);
                i++;
            }
        } else {
            i++; 
        }

        displayStack();
        displayInput(i);

        while (checkReduction()) {
            displayStack();
            displayInput(i);
        }
    }

    while (checkReduction()) {
        displayStack();
        printf("\n");
    }

    if (top == 0 && stack[top] == 'E') {
        printf("\nString is accepted.\n");
    } else {
        printf("\nString is rejected.\n");
    }

    return 0;
}

