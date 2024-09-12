#include <stdio.h>
#include <string.h>

#define MAX 10
char firstS[MAX], firstA[MAX], firstB[MAX];
int indexS = 0, indexA = 0, indexB = 0;
void add_to_first(char set[], char symbol, int *index) {
    for (int i = 0; i < *index; i++) {
        if (set[i] == symbol) {
            return; 
        }
    }
    set[(*index)++] = symbol;
}

void first_A() {
   
    add_to_first(firstA, 'e', &indexA);
}
void first_B() {
 add_to_first(firstB, 'e', &indexB);
}
void first_S() {
    add_to_first(firstS, 'a', &indexS);
    add_to_first(firstS, 'b', &indexS);
    add_to_first(firstS, 'e', &indexS);
}

int main() {
    first_A();  
    first_B();  
    first_S();  

    // Print the FIRST sets
    printf("FIRST(S) = { ");
    for (int i = 0; i < indexS; i++) {
        printf("%c ", firstS[i]);
    }
    printf("}\n");

    printf("FIRST(A) = { ");
    for (int i = 0; i < indexA; i++) {
        printf("%c ", firstA[i]);
    }
    printf("}\n");

    printf("FIRST(B) = { ");
    for (int i = 0; i < indexB; i++) {
        printf("%c ", firstB[i]);
    }
    printf("}\n");

    return 0;
}

