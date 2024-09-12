#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10
char trailingE[MAX], trailingT[MAX], trailingF[MAX];
int indexE = 0, indexT = 0, indexF = 0;
void add_to_trailing(char set[], char symbol, int *index) {
    for (int i = 0; i < *index; i++) {
        if (set[i] == symbol) {
            return;
        }
    }
    set[(*index)++] = symbol;
}
void trailing_E() {
    for (int i = 0; i < indexT; i++) {
        add_to_trailing(trailingE, trailingT[i], &indexE);
    }
}
void trailing_T() {
    for (int i = 0; i < indexF; i++) {
        add_to_trailing(trailingT, trailingF[i], &indexT);
    }
    add_to_trailing(trailingT, '*', &indexT);
    for (int i = 0; i < indexF; i++) {
        add_to_trailing(trailingT, trailingF[i], &indexT);
    }
}

void trailing_F() {
  
    add_to_trailing(trailingF, ')', &indexF);
    add_to_trailing(trailingF, 'd', &indexF); 
}

int main() {

    trailing_F();  
    trailing_T();  
    trailing_E();  
    printf("TRAILING(E) = { ");
    for (int i = 0; i < indexE; i++) {
        printf("%c ", trailingE[i]);
    }
    printf("}\n");

    printf("TRAILING(T) = { ");
    for (int i = 0; i < indexT; i++) {
        printf("%c ", trailingT[i]);
    }
    printf("}\n");

    printf("TRAILING(F) = { ");
    for (int i = 0; i < indexF; i++) {
        printf("%c ", trailingF[i]);
    }
    printf("}\n");

    return 0;
}

