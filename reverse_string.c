#include <stdio.h>
#include <string.h>

/*  
    PROGRAM TITLE: String Reversal with Newline Handling
    DESCRIPTION: This program takes a user-input string, removes the trailing newline 
    (if present), calculates its length, and then reverses it using a two-pointer approach. 
    The reversed string is displayed as output.
*/

// Function to remove newline from fgets input
void removeNewline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';  // Replace newline with null terminator
    }
}

int main() {
    // INPUT: Get a string from the user
    char string[80];
    printf("Input string: ");
    fgets(string, sizeof(string), stdin);

    removeNewline(string);  // Remove trailing newline

    // Get actual length of the string after removing \n
    int size = strlen(string);
    printf("Length: %d\n", size);  // Display size for debugging

    // Reverse the string
    for (int i = 0; i < size / 2; i++) {
        char temp = string[i];
        string[i] = string[size - 1 - i];
        string[size - 1 - i] = temp;
    }

    // OUTPUT: Display reversed string
    printf("Reversed String: %s\n", string);

    return 0;
}
