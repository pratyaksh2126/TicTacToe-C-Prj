#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>

// 2D array to represent the tic tac toe board
extern char board[3][3];

// Function prototypes
void init_board();
void display_board();
char check_win();
void player_turn(int player_num, char marker);

#endif
