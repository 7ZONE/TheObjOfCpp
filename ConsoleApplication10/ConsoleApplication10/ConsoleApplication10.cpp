// ConsoleApplication10.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include<iostream>
using namespace std;
class A
{
	int x;
public:
	A()
	{
		cout << "Constructor A ���к��� ��һ�����캯��" << endl;
		x = 1;

	}
	A(int a)//a2
	{
		cout << "constructor A �ڶ������캯��" << endl;
		x = a;

	}
	~A()
	{
		cout << " �������� A " << endl;

	}

	void Show()
	{

		cout << "x=��" << x << endl;
	}
};
int main()
{
	A a1, a2(5);//a1 ��Ĭ�Ϲ��캯�� 
	a1.Show();//����ڶ����鹹
	a2.Show();//�������������
    return 0;
}

