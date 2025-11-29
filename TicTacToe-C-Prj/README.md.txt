# Tic Tac Toe Game in C  
### Project Report Overview

---

## 1. Title  
**Tic Tac Toe – Console Based Game in C (Two Player – Pass n Play)**

---

## 2. Abstract  
This project implements a simple two-player Tic Tac Toe game in the C programming language.  
The game uses a 3×3 board represented by a 2D array and allows two human players to take turns.  
The program checks for valid moves, win conditions, and draws.  
It demonstrates core programming concepts such as arrays, functions, loops, and condition checking.

---

## 3. Problem Definition  
The goal of the project is to design and implement a console-based Tic Tac Toe game for two players.  
The system must allow:

1. Alternated turns  
2. Input validation  
3. Display of current board state  
4. Detection of wins or draws  
5. Clean program termination with proper results  

---

## 4. System Design  

### **4.1 Modules Used**
The program is divided into the following modules:

- **init_board()** – Initializes the game board  
- **display_board()** – Prints the current board state  
- **player_turn()** – Allows each player to make a validated move  
- **check_win()** – Checks all win conditions (rows, columns, diagonals)  

---

### **4.2 Algorithm (Simplified)**

1. Initialize board  
2. Loop for maximum 9 turns  
3. Display the board  
4. Take input from current player  
5. Validate and update board  
6. Check win conditions  
7. Announce winner or draw  

---

## 5. Testing & Results

The program was tested with multiple valid and invalid moves.
All winning conditions were correctly detected:

1. Row wins
2. Column wins
3. Diagonal wins
4. Anti-diagonal wins

Draw scenarios were also verified successfully.

## 6. Conclusion & Future Work

The Tic Tac Toe game meets all requirements and functions correctly.

Future Enhancements:

1. Add AI opponent
2. Graphical User Interface (GUI)
3. Network-based multiplayer

## 7. Folder Structure 
/
|-- src/                 # Contains tictactoe.c
|-- include/             # Optional header files
|-- docs/                # ProjectReport.pdf
|-- assets/              # Screenshots, diagrams
|-- README.md            # This file
|-- sample_input.txt     # Optional

## 8. Authors

1. Pratyaksh Singh

SAP ID: 590023001
Batch: B45

2. Prashant Kumar

SAP ID: 590027491
Batch: B45

## 9. Implementation Details

### **9.1 Programming Language**
- C (Standard C, GCC compatible)

### **9.2 Complete Source Code**
The full implementation is in: The complete C source code for this project is located in the file:
src/TicTacToe.c


### **9.3 Program Code**
```c
#include <stdio.h>
#include <stdlib.h>

char board[3][3];

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
            player_turn(1, 'X');
        } else {
            player_turn(2, 'O');
        }

        winner = check_win();
        if (winner != ' ') {
            break;
        }
    }

    display_board();

    if (winner == 'X') printf("Congratulations! Player 1 (X) wins!\n");
    else if (winner == 'O') printf("Congratulations! Player 2 (O) wins!\n");
    else printf("It's a draw!\n");

    return 0;
}

void init_board() {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
}

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

void player_turn(int player_num, char marker) {
    int choice, row, column;

    while (1) {
        printf("Player %d (%c), enter a number (1-9): ", player_num, marker);
        scanf("%d", &choice);

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

char check_win() {
    int i;

    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' ';
}

