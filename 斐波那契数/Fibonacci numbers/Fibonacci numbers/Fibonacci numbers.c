#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>
//���n��쳲��������Ƕ��٣�
//쳲���������ǰ����֮�͵��ڵ�������
//���磺1 1 2 3 5 8 13 21 34 55����

//�ݹ�˼·
//Fib(6)
//[ Fib(5) + Fib(4)]
//[ Fib(4) + Fib(3)] +[ Fib(3) + Fib(2)]
//[ Fib(3) + Fib(2)] +[ Fib(2) + Fib(1)] +[ Fib(2) + Fib(1)] + Fib(2)
//[ Fib(2) + Fib(1)] + Fib(2)  + [Fib(2) + Fib(1)] + [Fib(2) + Fib(1)] + Fib(2)
//1+1+1+1+1+1+1+1

int Fib1(int n) //�ݹ�
{
	if (n <= 2) 
		return 1;
	else       //n>2�ŵݹ�
		return Fib1(n - 1) + Fib1(n - 2);	
}    

//ϵͳ����������ջ�ռ������޵ģ���Fib�Ĳ�������ʱ��
//Fib�ݹ��ָ����չ�������ܻ����stack overflow(ջ���)
//��ʱ�ݹ鲢�����ѡ��

//int Fib2(int n) //�ǵݹ�
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
	printf("������n\n");
	scanf("%d", &n);

	ret = Fib1(n);
	//ret = Fib2(n);

	printf("��n��쳲�������Ϊ��%d\n", ret);
	return 0;
}




