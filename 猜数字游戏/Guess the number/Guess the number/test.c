#include "game.h"
int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	
	
	do
	{
		Menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:game();
			break;
		default:printf("�������������ѡ��\n");
			break;
		}
		
	} while (input);
	

	return 0;
}