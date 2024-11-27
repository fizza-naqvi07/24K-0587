#include <stdio.h>
#include <string.h>

void printString(char str[], int index) {
    if (str[index] == '\0') {
        return;
    }
    printf("%c", str[index]);
    printString(str, index + 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = 0;

    printf("The string is: ");
    printString(str, 0);

    return 0;
}


