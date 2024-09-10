 #include <stdio.h> #include <string.h> #include <ctype.h> #include <stdlib.h>

int tempVarCount = 0;	// Counter for temporary variables


// Function to generate a new temporary variable char* newTemp() {
static char temp[5];
sprintf(temp, "t%d", tempVarCount++); return temp;
}


// Function to print three-address code
void generateTAC(char* left, char op, char* right, char* result) { printf("%s = %s %c %s¥n", result, left, op, right);
}


// Recursive function to parse the expression and generate TAC char* parseExpression(char* expr, int start, int end) {
int i, lastOp = -1, opPosition = -1, parentheses = 0;


// Find the last operator in the expression that is outside of any parentheses
for (i = start; i <= end; i++) { if (expr[i] == '(') {
parentheses++;
} else if (expr[i] == ')') { parentheses--;
} else if (parentheses == 0 && (expr[i] == '+' || expr[i] == '-')) { lastOp = i;
} else if (parentheses == 0 && (expr[i] == '*' || expr[i] == '/') && lastOp == -1) {
opPosition = i;

}
}


if (lastOp == -1) { lastOp = opPosition;
}
if (lastOp == -1) {
if (expr[start] == '(' && expr[end] == ')') {
return parseExpression(expr, start + 1, end - 1);
} else {
char* operand = (char*)malloc(2); operand[0] = expr[start]; operand[1] = '¥0';
return operand;

}
}


char* left = parseExpression(expr, start, lastOp - 1); char* right = parseExpression(expr, lastOp + 1, end); char op = expr[lastOp];
char* result = newTemp();


generateTAC(left, op, right, result);


return result;
}


int main() {
char expr[100];


printf("Enter an arithmetic expression: ");
scanf("%s", expr);


int len = strlen(expr); parseExpression(expr, 0, len - 1);


return 0;
}

