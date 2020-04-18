#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//喝汽水问题：喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
//int main()
//{
//	int money;
//	printf("请输入money:\n");
//	scanf("%d", &money);
//	//买回来的汽水喝掉
//	int total = money;
//	int empty = money;
//	//空瓶换回来的汽水
//	while (empty>=2)//空瓶多于两个才能换汽水
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("总共可以喝 %d 汽水\n", total);
//	return 0;
//
//}

int main()
{
	int money;
	printf("请输入money:\n");
	scanf("%d", &money);
	//买回来的汽水喝掉
	int total = money;
	int empty = money;
	if (money <=0) //负数和0均不能喝汽水
		total = 0;
	else
		total = 2 * money - 1;
	printf("总共可以喝 %d 汽水\n", total);
	return 0;

}