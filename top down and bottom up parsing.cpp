#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;
char input[MAX];

int i = 0;
int error = 0;

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
}

void E();
void Eprime();
void T();
void Tprime();
void F();

void E() {
    printf("E -> T E'\n");
    T();
    Eprime();
}

void Eprime() {
    if (input[i] == '+') {
        printf("E' -> + T E'\n");
        i++;
        T();
        Eprime();
    } else {
        printf("E' -> e\n");
    }
}

void T() {
    printf("T -> F T'\n");
    F();
    Tprime();
}

void Tprime() {
    if (input[i] == '*') {
        printf("T' -> * F T'\n");
        i++;
        F();
        Tprime();
    } else {
        printf("T' -> e\n");
    }
}

void F() {
    if (input[i] == '(') {
        printf("F -> ( E )\n");
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            error = 1;
        }
    } else if (isalnum(input[i])) {
        printf("F -> id\n");
        i++;
    } else {
        error = 1;
    }
}

int reduce() {
    if (top >= 2) {
        if (stack[top] == 'E' && stack[top-1] == '+' && stack[top-2] == 'E') {
            pop(); pop(); pop(); push('E');
            return 1;
        }
    }

    if (top >= 2) {
        if (stack[top] == 'E' && stack[top-1] == '*' && stack[top-2] == 'E') {
            pop(); pop(); pop(); push('E');
            return 1;
        }
    }

    if (top >= 2) {
        if (stack[top] == ')' && stack[top-1] == 'E' && stack[top-2] == '(') {
            pop(); pop(); pop(); push('E');
            return 1;
        }
    }

    if (top >= 0) {
        if (stack[top] == 'i') {
            pop(); push('E');
            return 1;
        }
    }

    return 0;
}

int main() {
    int choice;
    
    printf("Enter the arithmetic expression: ");
    scanf("%s", input);
    
    printf("Choose Parsing Method:\n");
    printf("1. Top-Down Parsing (Recursive Descent)\n");
    printf("2. Bottom-Up Parsing (Shift-Reduce)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nTop-Down Parsing (Recursive Descent):\n");
        E();
        if (strlen(input) == i && error == 0) {
            printf("String is accepted.\n");
        } else {
            printf("String is rejected.\n");
        }
    } else if (choice == 2) {
        printf("\nBottom-Up Parsing (Shift-Reduce):\n");
        int i = 0;
        printf("STACK\tINPUT\tACTION\n");
        printf("-----\t-----\t------\n");

        while (input[i] != '\0') {
            push(input[i]);
            i++;
            displayStack();
            printf("\t%s\tSHIFT\n", input + i);

            while (reduce()) {
                displayStack();
                printf("\t%s\tREDUCE\n", input + i);
            }
        }

        while (reduce()) {
            displayStack();
            printf("\t\tREDUCE\n");
        }

        if (top == 0 && stack[top] == 'E') {
            printf("String is accepted.\n");
        } else {
            printf("String is rejected.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

