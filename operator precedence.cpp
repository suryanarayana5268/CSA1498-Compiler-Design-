#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

void add_leading(char non_terminal, char leading[], char grammar[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        if (grammar[i][0] == non_terminal) {
            if (!isupper(grammar[i][2])) {
                
                strncat(leading, &grammar[i][2], 1);
            } else {
                
                add_leading(grammar[i][2], leading, grammar, n);
            }
        }
    }
}

int main() {
    int n;
    char grammar[MAX][MAX], leading[MAX];
    char non_terminals[MAX];
    
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    
    printf("Enter the grammar (each production on a new line, e.g., E=E+T):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", grammar[i]);
    }
    
   
    for (int i = 0; i < n; i++) {
        non_terminals[i] = grammar[i][0];
    }

   
    for (int i = 0; i < n; i++) {
        leading[0] = '\0'; 
        add_leading(non_terminals[i], leading, grammar, n);
        printf("LEADING(%c) = { %s }\n", non_terminals[i], leading);
    }

    return 0;
}

