#define _CRT_SECURE_NO_WARNINGS 1  
//һֻ���ӵ����ݾ����ÿ�춼��������n���ף�����������Ϣʱ���½���������
//ͨ���������֣���һ�����ϳ��ӻ��½�n/2���ף���2�����ϳ��ӻ��½���n/2+n/4������
//��3�����ϳ��ӻ��½���n/2+n/4+n/8�����ס����Դ�����
//�������Ϊm��������ֻŬ���ĳ��ӵڼ����ܹ������ݾ���
//����������
//�������
//ÿ����������ռ1��
//ÿ����������������n��m,��50*m<n<100*m
//m<=100 �������ݱ�֤�����н�



#include <iostream>
using namespace std;
int main()
{//����high==m ����up==n �½�down
	double high, up;
	double down = 0;
	scanf("%d %d", &high, &up);
	double n = 1, s = 0;//s���ۼ����� n����
	while (1)
	{
		s += up;
		if (s<high) //δ�����
		{
			down += up/pow(2, n);
			s -= down;
			n++;
		}
		//�����
		else
		{
			cout << n << endl;
			break;
		}
		
	}
	return 0;
}