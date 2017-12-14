 sanziqixiangmu
 game.c
 #define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', row*col * sizeof(board[0][0]));
}
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			printf(" %c ", board[i][j]);
			if (j != col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i != row - 1)
		{
			printf("---|---|---\n");
		}
	}
	printf("\n");
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	
while(1)
	{
printf("请输入坐标:>");
scanf("%d%d", &x, &y);
if (((x - 1) >= 0 && (x - 1) <= 2) && ((y - 1) <= 2 && (y - 1) >= 0))
{
	if (board[x - 1][y - 1] == ' ')
	{
		board[x - 1][y - 1] = 'X';
		break;
	}
	else
	{
		printf("\n输入不合法,请重新输入:>");
	}
}
else
{
	printf("输入不合法,请重新输入:>\n");
	}

}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % row;

y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}

int full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}		
		}
		
	}
       return 1;
}
char CheckBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; ++i)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][0] != ' ')
		{
			return board[0][i];
		}
	}
	for (j = 0; j < col; ++j)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) &&( board[0][j] != ' '))
		{
			return board[0][j];
		}
	}
	if (((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[1][1] != ' ')))
	{
		return board[1][1];
	}
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) &&( board[1][1] != ' '))
	{
	  return board[1][1];
    }
		
    if (full(board, ROW, COL)==1)
	{
		return 'q';
	}
	return ' ';
}
game.h

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
#endif    //

test.c
#define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("*********************************************\n");
	printf("************1.play   0.exit******************\n");
	printf("*********************************************\n");
}
void game()
{   
	char board[ROW][COL] = { 0 } ;
	char ret = '0';
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	srand((unsigned int)time(NULL));
	while (1)
	{
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = CheckBoard(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
        ret = CheckBoard(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
	}
		if (ret == 'X')
		{
			printf("玩家赢\n");
		}
		if (ret == '0')
		{
			printf("电脑赢\n");
		}
		if (ret == 'q')
		{
			printf("平局\n");	
		}
}
int main()
{  
	int input = 0;
	do
	{   
		menu();
		printf("请输入选项:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			break;
		}

	} while (input);

	return 0;
}
