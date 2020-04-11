#include "game.h"
void Menu()//初始菜单
{
	printf("***************************************\n");
	printf("*********   Welcome to game  **********\n");
	printf("*********        1.Play      **********\n");
	printf("*********        0.Exit      **********\n");
	printf("***************************************\n");
}
void game()
{
	int random_num = rand() % 100 + 1;//生成一个0-100的随机数
	int input;
	printf("游戏开始\n");
	while (1)
	{
		printf("请输入你猜的数字\n");
		scanf("%d", &input);
		if (input > random_num)
		{
			printf("猜大了\n");
		}
		else if (input < random_num)
		{
			printf("猜小了\n");
		}
		else if (input == random_num)
		{
			printf("恭喜你猜对了\n");
			break; //猜对跳出游戏
		}
	}
	system("pause");//一次游戏结束后暂停
	system("cls");//清屏
}
