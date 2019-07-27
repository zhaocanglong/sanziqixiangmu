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
			printf("���Ӯ\n");
		}
		if (ret == '0')
		{
			printf("����Ӯ\n");
		}
		if (ret == 'q')
		{
			printf("ƽ��\n");	
		}
}
int main()
{  
	int input = 0;
	do
	{   
		menu();
		printf("������ѡ��:>");
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