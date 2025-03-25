#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remSpace (char string[], int size);
void removeNewLine(char string[], int *size);
void reverse (char string[]);

int main() {
    char string[80];

    // Step 1: Get Input from User
    printf("Input String: ");
    fgets(string, sizeof(string), stdin);

    int size = strlen(string);
    removeNewLine(string, &size); // Step 2: Remove newline if present

    remSpace(string, size); // Step 3: Remove spaces
    reverse(string); // Step 4: Check palindrome
}

void removeNewLine(char string[], int *size) {
    if (string[*size - 1] == '\n') { // Only remove if \n is present
        string[*size - 1] = '\0';
        (*size)--; // Update size after removal
    }
}

void remSpace (char string[], int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (!isspace(string[i])) {
            string[j] = string[i]; // Shift non-space characters
			j++;
        }
    }
    string[j] = '\0'; // Null terminate new string

    printf("String: %s\n", string);
}

void reverse (char string[]) {
    char rev[80];
    int size = strlen(string);

    strcpy(rev, string);

    for (int i = 0; i < size / 2; i++) {
        // Swap elements
        char temp = rev[i];
        rev[i] = rev[size - 1 - i];
        rev[size - 1 - i] = temp;
    }

    // Check if the original string is a palindrome
    if (strcmp(rev, string) == 0) {
        printf("It is a palindrome!\n\nString: %s\nReversed: %s\n", string, rev);
    } else {
        printf("It is not a palindrome!\n\nString: %s\nReversed: %s\n", string, rev);
    }
}
