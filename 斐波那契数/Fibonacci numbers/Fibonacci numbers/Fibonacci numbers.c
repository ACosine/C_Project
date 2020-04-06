#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>
//求第n个斐波那契数是多少？
//斐波那契数：前两数之和等于第三个数
//例如：1 1 2 3 5 8 13 21 34 55……

//递归思路
//Fib(6)
//[ Fib(5) + Fib(4)]
//[ Fib(4) + Fib(3)] +[ Fib(3) + Fib(2)]
//[ Fib(3) + Fib(2)] +[ Fib(2) + Fib(1)] +[ Fib(2) + Fib(1)] + Fib(2)
//[ Fib(2) + Fib(1)] + Fib(2)  + [Fib(2) + Fib(1)] + [Fib(2) + Fib(1)] + Fib(2)
//1+1+1+1+1+1+1+1

int Fib1(int n) //递归
{
	if (n <= 2) 
		return 1;
	else       //n>2才递归
		return Fib1(n - 1) + Fib1(n - 2);	
}    

//系统分配给程序的栈空间是有限的，当Fib的参数过大时，
//Fib递归呈指数扩展开，可能会出现stack overflow(栈溢出)
//此时递归并非最佳选择

//int Fib2(int n) //非递归
//{
//	int a = 1, b = 1, c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}


int main()
{
	int n = 0, ret = 0;
	printf("请输入n\n");
	scanf("%d", &n);

	ret = Fib1(n);
	//ret = Fib2(n);

	printf("第n个斐波那契数为：%d\n", ret);
	return 0;
}




