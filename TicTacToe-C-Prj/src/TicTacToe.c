#include <stdio.h>
#include <stdlib.h>

// 2D array to represent the tic tac toe board
char board[3][3];

// Function prototypes
void init_board();
void display_board();
char check_win();
void player_turn(int player_num, char marker);

int main() {
    char winner = ' ';
    int turn;

    printf("Welcome to Tic Tac Toe Game (Pass n play -Two players only).\n");
    printf("Player 1 is X, Player 2 is O.\n\n");

    init_board();

    for (turn = 1; turn <= 9; turn++) {
        display_board();

        if (turn % 2 != 0) {
            player_turn(1, 'X'); // Player 1's turn
        } else {
            player_turn(2, 'O'); // Player 2's turn
        }

        winner = check_win();
        if (winner != ' ') {
            break;
        }
    }

    display_board(); // Display the final board

    if (winner == 'X') {
        printf("Congratulations! Player 1 (X) wins!\n");
    } else if (winner == 'O') {
        printf("Congratulations! Player 2 (O) wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

// Function to initialize the board with empty spaces
void init_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the current board
void display_board() {
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X) - Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("__|_|__\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("__|_|__\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}

// Function to get a player's move
void player_turn(int player_num, char marker) {
    int choice, row, column;

    while (1) {
        printf("Player %d (%c), enter a number (1-9): ", player_num, marker);
        scanf("%d", &choice);

        // Map the 1-9 choice to array indices
        row = (choice - 1) / 3;
        column = (choice - 1) % 3;

        if (choice >= 1 && choice <= 9 && board[row][column] == ' ') {
            board[row][column] = marker;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

// Function to check for a winner or a draw
char check_win() {
    int i;
    // Check for horizontal and vertical wins
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0]; // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i]; // Column win
    }

    // Check for diagonal wins
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0]; // Diagonal win
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2]; // Anti-diagonal win

    // If no winner, return ' ' (still playing)
    return ' ';
}