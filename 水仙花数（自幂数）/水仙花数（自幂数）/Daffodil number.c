#define _CRT_SECURE_NO_WARNINGS 1  
/******************************************1.水仙花数**************************************/
//水仙花数又称自幂数：
//一个n位数，其各位数字的n次方之和确好等于该数本身
int main()
{
	int i;
	for (i = 0; i <= 100000; ++i)
	{
		int n = 1;
		int sum = 0;//每次循环进来sum都应为0

		//1.判断i的位数n
		int temp1 = i;//参数保护
		while (temp1 /= 10)
		{
			n++;
		}
		//2.每一位的n次方之和sum
		int temp2 = i;//参数保护
		while (temp2)
		{
			sum += (int)pow((temp2 % 10), n);//sprt开平方pow次方 返回类型double
			temp2 /= 10;
		}
		//3.判断此次循环中i是否等于sum
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	return 0;
}