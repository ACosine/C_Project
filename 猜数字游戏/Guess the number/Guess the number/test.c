#include "game.h"
int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	
	
	do
	{
		Menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:game();
			break;
		default:printf("输入错误，请重新选择：\n");
			break;
		}
		
	} while (input);
	

	return 0;
}