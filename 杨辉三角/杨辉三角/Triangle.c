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
	//1.����
	for (i =0 ; i < Row; ++i)
	{
		int j;
		for (j = 0; j <= i; ++j)
		{
			//1.1����
			if (j == 0);
				arr[i][0] = 1;
			//1.2���Խ���
			if (i == j)
				arr[i][j] = 1;
			//1.3������
			if ((i>=2)&&(j>=1))
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}


	//2. ��ӡ
	for (i = 0; i < Row; ++i)
	{
		int j;
		//2.1��ӡ�ո�
		for (j = 0; j < Row - 1 - i; ++j)
			//��һ�пո�Row-1-0  �ڶ���Row-1-1 ������Row-1-2 ����i��Row-1-i
		{
			printf(" ");
		}
		//2.1��ӡ����
		for (j = 0; j <= i; ++j)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
//�Ľ�