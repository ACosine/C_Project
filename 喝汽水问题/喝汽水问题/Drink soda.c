#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����ˮ���⣺����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
//int main()
//{
//	int money;
//	printf("������money:\n");
//	scanf("%d", &money);
//	//���������ˮ�ȵ�
//	int total = money;
//	int empty = money;
//	//��ƿ����������ˮ
//	while (empty>=2)//��ƿ�����������ܻ���ˮ
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("�ܹ����Ժ� %d ��ˮ\n", total);
//	return 0;
//
//}

int main()
{
	int money;
	printf("������money:\n");
	scanf("%d", &money);
	//���������ˮ�ȵ�
	int total = money;
	int empty = money;
	if (money <=0) //������0�����ܺ���ˮ
		total = 0;
	else
		total = 2 * money - 1;
	printf("�ܹ����Ժ� %d ��ˮ\n", total);
	return 0;

}