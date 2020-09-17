#define _CRT_SECURE_NO_WARNINGS 1  
//一只虫子掉进枯井里，它每天都会向上爬n厘米，但是晚上休息时会下降若干厘米
//通过分析发现，第一天晚上虫子会下降n/2厘米，第2天晚上虫子会下降（n/2+n/4）厘米
//第3天晚上虫子会下降（n/2+n/4+n/8）厘米……以此类推
//如果井深为m米请问这只努力的虫子第几天能够爬出枯井？
//输入描述：
//单组输出
//每组输入数据占1行
//每行输入两个正整数n和m,且50*m<n<100*m
//m<=100 输入数据保证问题有解



#include <iostream>
using namespace std;
int main()
{//井深high==m 上升up==n 下降down
	double high, up;
	double down = 0;
	scanf("%d %d", &high, &up);
	double n = 1, s = 0;//s是累计上升 n天数
	while (1)
	{
		s += up;
		if (s<high) //未爬出深井
		{
			down += up/pow(2, n);
			s -= down;
			n++;
		}
		//爬出深井
		else
		{
			cout << n << endl;
			break;
		}
		
	}
	return 0;
}