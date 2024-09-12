#include <stdio.h>
#include <string.h>

#define MAX 10
char followS[MAX], followA[MAX], followB[MAX];
int indexS = 0, indexA = 0, indexB = 0;
void add_to_follow(char set[], char symbol, int *index) {
    for (int i = 0; i < *index; i++) {
        if (set[i] == symbol) {
            return; 
        }
    }
    set[(*index)++] = symbol;
}
void follow_S() {
    add_to_follow(followS, '$', &indexS);
}
void follow_A() {
    add_to_follow(followA, 'a', &indexA);
    add_to_follow(followA, '$', &indexA);
}
void follow_B() {
    add_to_follow(followB, 'b', &indexB);

    add_to_follow(followB, '$', &indexB);
}

int main() {
   
    follow_S();  
    follow_A();  
    follow_B(); 
    printf("FOLLOW(S) = { ");
    for (int i = 0; i < indexS; i++) {
        printf("%c ", followS[i]);
    }
    printf("}\n");

    printf("FOLLOW(A) = { ");
    for (int i = 0; i < indexA; i++) {
        printf("%c ", followA[i]);
    }
    printf("}\n");

    printf("FOLLOW(B) = { ");
    for (int i = 0; i < indexB; i++) {
        printf("%c ", followB[i]);
    }
    printf("}\n");

    return 0;
}

