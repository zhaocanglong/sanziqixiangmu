#ifndef  ____game__h___
#define  ____game__h___


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL], int row, int col);
void PrintBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char CheckBoard(char board[ROW][COL], int row, int col);
#endif    //_____game_h___