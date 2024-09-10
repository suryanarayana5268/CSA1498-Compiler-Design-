#include <stdio.h> #include <ctype.h>

int main() {
char ch;
int charCount = 0, wordCount = 0, lineCount = 0; int inWord = 0;

printf("Enter text (Ctrl+D to end):¥n");


while ((ch = getchar()) != EOF) {
charCount++;


if (ch == '¥n') { lineCount++;
}


if (isspace(ch)) { inWord = 0;
} else if (!inWord) { inWord = 1; wordCount++;
}
}


// To account for the last line if it doesn't end with a newline if (charCount > 0 && ch != '¥n') {
lineCount++;

}


printf("Characters: %d¥n", charCount); printf("Words: %d¥n", wordCount); printf("Lines: %d¥n", lineCount);


return 0;
}

