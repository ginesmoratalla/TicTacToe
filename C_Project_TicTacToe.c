#include <stdio.h>
#include <stdlib.h>

int row_covered(char table[55][55], int n) {
    table[n][n]; // Although not necessary, it sets the board to be n x n, to work only with the space of the bord input by user
    int i, j, x, o;
    // rows 
    for (i = 0; i < n; i++) {
        x = 0;
        o = 0;
        for (j = 0; j < n; j++) {
            if (table[i][j] == 'x') {
                x++; // counts how many 'x' there are in each row
            } else if (table[i][j] == 'o') {   
                o++; // counts how many 'o' there are in each row
            }
        }
        if (x == n) {
            return 1; // If one of the rows is covered by 'x' it returns player 1 as winner
        } else if (o == n) {
            return 2; // If one of the rows is covered by 'o' it returns player 2 as winner
        }
    }
    // columns
    for (j = 0; j < n; j++) {
        x = 0;
        o = 0;
        for (i = 0; i < n; i++) {
            if (table[i][j] == 'x') {
                x++; // counts how many 'x' there are in each column
            } else if (table[i][j] == 'o') {
                o++; // counts how many 'o' there are in each column
            }
        }
        if (x == n) {
            return 1; // If one of the columns is covered by 'x' it returns player 1 as winner
        } else if (o == n) {
            return 2; // If one of the columns is covered by 'o' it returns player 2 as winner
        }
    }
    // diagonal 1,1 to n,n
    for (i = 0; i < n; i++) {
        x = 0;
        o = 0;
        for (i = 0; i < n; i++) {
            if (table[i][i] == 'x') {
                x++;  // counts how many 'x' there are in the first diagonal
            } else if (table[i][i] == 'o') {
                o++;  // counts how many 'o' there are in the first diagonal
            }
        }
        if (x == n) {
            return 1; // If the first diagonal is covered by 'x' it returns player 1 as winner
        } else if (o == n) {
            return 2; // If the first diagonal is covered by 'o' it returns player 2 as winner
        }
    }
    // diagonal 1,n to n,1
    for (i = 0; i < n; i++) {
        x = 0;
        o = 0;
        for (i = 0; i < n; i++) {
            if (table[i][n - i - 1] == 'x') {
                x++;  // counts how many 'x' there are in the second diagonal
            } else if (table[i][n - i - 1] == 'o') {
                o++;  // counts how many 'o' there are in the second diagonal
            }
        }
        if (x == n) {
            return 1; // If the second diagonal is covered by 'x' it returns player 1 as winner
        } else if (o == n) { 
            return 2; // If the second diagonal is covered by 'o' it returns player 2 as winner
        }
    }
    return 0;
}
void print_grid(char table[55][55], int n, int row, int column, int row2, int column2, int r, int l) {
    table[n][n]; // Although not necessary, it sets the board to be n x n, to work only with the space of the bord input by user
    if (r == 1) { // If r is 1, it means that it is Player 1's turn
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                table[row - 1][column - 1] = 'x'; // Sets an 'x' in the position input by Player 1
            }
        }
        printf("\nBoard: \n\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c ", table[i][j]);
            }
            printf("\n"); // Player 1 finish
        }
    }
    if (l == 1) { // If r is 2, it means that it is Player 1's turn
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                table[row2 - 1][column2 - 1] = 'o'; // Sets an 'o' in the position input by Player 2
            }
            
        }
        printf("\nBoard: \n\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c ", table[i][j]);
            }
            printf("\n");  // Player 2 finish
        }
    }
}

int draw(char table[55][55], int n) {
    table[n][n]; // Although not necessary, it sets the board to be n x n, to work only with the space of the bord input by user
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == '-') {
                return 1;
            }
        }
    }
}
int main()
{
    int n; // Used for the number of elements (n x n) of our board
    int i, j; // Used for 'for' loops to print or scan the board
    int row, column; // Will be used to set 'x' in the position input by Player 1
    int row2, column2; // Will be used to set 'o' in the position input by Player 2
    int r, l; // Declared for function row_covered to know if its Player 1 who input a position or it was Player 2
    int *checkforwinner, *checkdraw;
    
    checkforwinner = (int*)malloc(sizeof(int));
    *checkforwinner = 0;
    // This pointer variables are allocated dinamically and will be used to check for the winner or draw, with the respective functions
    checkdraw = (int*)malloc(sizeof(int));
    *checkdraw = 0;
    
    char table[55][55];
    printf("- Hello users, today you are going to play Tic Tac Toe!\n\n- The rules are simple, one of you will use x, and the other will use o,\n  Player x will always start, so decide who will be x first.\n");
    de:
    printf("\n- Please, select the size 'n' of the board (n x n) you are going to be playing in : ");
    scanf("%d", &n);
    if ((n >= 2) && (n <= 50)) { // Checks if the value input by user is in the range of values asked in the exercise
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                table[i][j] = '-';
            }
        }
    } else {
        printf("\n- That size is invalid for the board\n"); // If the value is not between the range, it goes back to de: to ask the user again
        goto de;
    }

    printf("Your table will be: \n\n"); // prints the empty table
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    } 
    
    start1:
    printf("\nPlayer 1, input the position for your x (row and column): ");     // Player 1 starts
    scanf("%d %d", &row, &column);
    if (table[row - 1][column - 1] != '-') {                                    // Checks for marks already placed
        printf("\nThere is a mark there already OR that position does not exist, choose another position: \n");
        goto start1; // If a mark is already placed there or position does not exist, goes back to start1: to ask the user again
    }
    r = 1; // r is 1 so it can be detected by function print_grid to place an 'x' and not an 'o'
    print_grid(table, n, row, column, row2, column2, r, l);                     
    *checkforwinner = row_covered(table, n);
    if (*checkforwinner == 1) {
        printf("\nPlayer 1 won");
        return 0; // If the winner is checked in row_covered, program ends
    }
    *checkdraw = draw(table, n);   // Draw function checks if all the positions are covered by x and o
    if (*checkdraw != 1) {     
        printf("\nGame ends in draw.");
        return 0; // If there is a draw, the program ends
    }
    r = 0; // r back to 0 so it won't be detected again in the checkforwinner and Player 1 finish
    
    start2:
    printf("\nPlayer 2, input the position for your o (row and column): ");     // Player 2 starts
    scanf("%d %d", &row2, &column2);
    if (table[row2 - 1][column2 - 1] != '-') {                                  // Checks for marks already placed
        printf("\nThere is a mark there already OR that position does not exist, choose another position: \n");
        goto start2; // If a mark is already placed there or position does not exist, goes back to start2: to ask the user again
    }
    l = 1; // l is 1 so it can be detected by function print_grid to place an 'o' and not an 'x'
    print_grid(table, n, row, column, row2, column2, r, l); // Sets the mark on the position
    *checkforwinner = row_covered(table, n);
    if (*checkforwinner == 2) {
        printf("\nPlayer 2 won");
        return 0; // If the winner is checked in row_covered, program ends
    }
    *checkdraw = draw(table, n); // checks for a draw with draw function
    if (*checkdraw != 1) {
        printf("\nGame ends in draw.");
        return 0;
    }
    l = 0;  // l back to 0 so it won't be detected again in the checkforwinner and Player 2 finish
    goto start1; // loops back to Player 1
    
    free(checkforwinner);
    free(checkdraw);
    return 0;
}