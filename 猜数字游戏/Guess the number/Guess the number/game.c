#include "game.h"
void Menu()//��ʼ�˵�
{
	printf("***************************************\n");
	printf("*********   Welcome to game  **********\n");
	printf("*********        1.Play      **********\n");
	printf("*********        0.Exit      **********\n");
	printf("***************************************\n");
}
void game()
{
	int random_num = rand() % 100 + 1;//����һ��0-100�������
	int input;
	printf("��Ϸ��ʼ\n");
	while (1)
	{
		printf("��������µ�����\n");
		scanf("%d", &input);
		if (input > random_num)
		{
			printf("�´���\n");
		}
		else if (input < random_num)
		{
			printf("��С��\n");
		}
		else if (input == random_num)
		{
			printf("��ϲ��¶���\n");
			break; //�¶�������Ϸ
		}
	}
	system("pause");//һ����Ϸ��������ͣ
	system("cls");//����
}
