#include <stdio.h>
#include <string.h>

// Function to validate integer input for 'steps'
void checkError(int *n, int *nCheck);

// Recursive function to execute the Josephus elimination process
void josephus(char a[5][10], int size, int steps, int index);

int main() {
    // Step 1: Initialization of variables
    int size = 5, index = 0; // 'size' is fixed to 5 players
    char a[size][10]; // 2D array to store names (5 names, max 10 chars each)

    int steps, sCheck;
    
    // Step 2: Get user input for the number of steps (with validation)
    printf("Input the no. of steps: ");
    sCheck = scanf("%d", &steps);
    
    // Ensure user enters a nnon-zero, valid positive integer for steps
    while (sCheck != 1 || steps <= 0) {
        checkError(&steps, &sCheck);
    }

    int aCheck;
    printf("Input Player's Name (Max 10 characters).\n");

    // Step 3: Get player names with input validation
    for (int i = 0; i < size; i++) {
        printf("Player %d: ", i + 1);
        aCheck = scanf("%s", a[i]);  // Limits input to 9 characters (leaves space for '\0')

        // 🔹 Validate name length (must be ≤9 characters)
        while (aCheck != 1 || strlen(a[i]) > 9) {
            if (aCheck != 1) { 
                while (getchar() != '\n'); // Clear input buffer
                printf("Invalid Input! Try Again: ");
                aCheck = scanf("%s", a[i]);
            }
            else if (strlen(a[i]) > 9) {
                while (getchar() != '\n'); // Clear input buffer
                printf("Exceeded Max Characters! Try Again: ");
                aCheck = scanf("%s", a[i]);
            }
        }
    }

    // Step 4: Start the Josephus elimination process
    josephus(a, size, steps, index);
}

// Function to handle incorrect input for step count
void checkError(int *n, int *nCheck) {
    while (getchar() != '\n'); // Clear buffer
    printf("Number(s) only! Input again: ");
    *nCheck = scanf("%d", n);
}

// Recursive function for Josephus elimination
void josephus(char a[5][10], int size, int steps, int index) {
    // Base case: If only one player remains, print the winner
    if (size == 1) {
        printf("🏆 Last man standing: %s\n", a[0]);
        return;
    }

    //  Step 1: Find the player to eliminate
    index = (index + (steps - 1)) % size;
    printf("❌ Eliminated: %s\n", a[index]);

    // Step 2: Print updated player list
    for (int i = 0; i < size; i++) {
        printf("+------------");
    }
    printf("+\n"); // Top border

    for (int i = 0; i < size; i++) {
        if (strcmp(a[i], a[index]) == 0) {  // If player is eliminated, mark it
            printf("|         :) ");
        }
        else {
            printf("| %10s ", a[i]);
        }
    }
    printf("|\n"); // Closing side border

    for (int i = 0; i < size; i++) {
        printf("+------------");
    }
    printf("+\n\n\n"); // Bottom border

    getchar();
    getchar();

    // Step 3: Shift elements to remove eliminated player
    for (int i = index; i < size - 1; i++) {
        strcpy(a[i], a[i + 1]);
    }

    // Recursive call with updated list
    josephus(a, size - 1, steps, index);
}
