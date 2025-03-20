#include <stdio.h>

/*
===============================================================================
                            JOSEPHUS PROBLEM (RECURSION)
===============================================================================
    A puzzle-based elimination game where `n` players are standing in a 
    circle and every `k`-th player is eliminated until only one remains.
    
    HOW IT WORKS:
    - Players are stored in an array.
    - Starts at index 0, then moves `k-1` steps forward to find the eliminated player.
    - After elimination, remaining players shift left.
    - Recursion continues until only one survivor remains.

    FEATURES:
    - Uses **recursion** for elimination.
    - **Circular elimination** using modulo.
    - **Visual representation** of the eliminations.
    - **Pause between steps** for better tracking.

    INPUT:
    - Number of steps `k`
    - Number of players `n`
    - Player numbers

    OUTPUT:
    - Elimination sequence with a bordered visualization.
    - The last man standing.

===============================================================================
*/

void josephus(int a[], int n, int k, int index);

int main() {
    int k, n, index = 0;
    printf("Input the number of steps: ");
    scanf("%d", &k);

    printf("Input the number of players: ");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("Elimination Sequence:\n\n");
    josephus(a, n, k, index);
}

void josephus(int a[], int n, int k, int index) {
    //base case: stop recursion if there's only 1 left
    if (n == 1) {
        printf("\n\nLAST MAN STANDING: %d\n", a[0]);
        return;
    }


    //recursive case
    else {
        //Process 1: Find the element to be eliminated
        index = (index + k - 1) % n;
        /* step-by-step process explanation:
        index - tracks where we previously are after elimination
        k - 1 - in an array the kth element is always k - 1 due to 0 based indexing
        % n - incase we have traversed all elements and we're at the last element, we circle back to the 1st element till we reach the kth step
        */
        printf("\n\nEliminated: %d\n\n", a[index]);


        //OUTPUT 1: Bordered Visualization of Eliminated Element
        for (int i = 0; i < n; i++) {
            printf("+----");
        }
        printf("+\n");

        for (int i = 0; i < n; i++) {
            if (a[i] == a[index]) {
                printf("| :) ");
            }
            else
                printf("| %2d ", a[i]);
        }
        printf("|\n");

        for (int i = 0; i < n; i++) {
            printf("+----");
        }
        printf("+\n");



        //Process 2: Shift the elements after deducting 1
        for (int i = index; i < n - 1; i++) {
            a[i] = a[i + 1];
        }

        getchar();  // Waits for any key press (use twice because of leftover '\n' in buffer)
        getchar();



        //Process 3: Repeat the process
        josephus(a, n - 1, k, index);
    }
}
