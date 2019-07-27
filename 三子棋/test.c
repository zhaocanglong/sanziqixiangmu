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