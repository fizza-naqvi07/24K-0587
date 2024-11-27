#include <stdio.h>
#include <string.h>

void reverseWordsOrder(char str[], int start, int end) {
    if (start > end) {
        return;
    }

    int wordEnd = start;
    while (wordEnd <= end && str[wordEnd] != ' ') {
        wordEnd++;
    }

    reverseWordsOrder(str, wordEnd + 1, end); 

    for (int i = start; i < wordEnd; i++) {
        printf("%c", str[i]);
    }

    if (wordEnd <= end) {
        printf(" ");
    }
}

int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 

    reverseWordsOrder(str, 0, strlen(str) - 1);
    return 0;
}