#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>
#define  Row 5
#define Col 5

//
//
//1
//1 1
//1 2 1
//1 3 3 1
//
//   1
//  1 1
// 1 2 1
//1 3 3 1


int main()
{
	int arr[Row][Col] = { 0 };
	int i;
	//1.计算
	for (i =0 ; i < Row; ++i)
	{
		int j;
		for (j = 0; j <= i; ++j)
		{
			//1.1首列
			if (j == 0);
				arr[i][0] = 1;
			//1.2主对角线
			if (i == j)
				arr[i][j] = 1;
			//1.3三角线
			if ((i>=2)&&(j>=1))
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}


	//2. 打印
	for (i = 0; i < Row; ++i)
	{
		int j;
		//2.1打印空格
		for (j = 0; j < Row - 1 - i; ++j)
			//第一行空格Row-1-0  第二行Row-1-1 第三行Row-1-2 …第i行Row-1-i
		{
			printf(" ");
		}
		//2.1打印数字
		for (j = 0; j <= i; ++j)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
//改进