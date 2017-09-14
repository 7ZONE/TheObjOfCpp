// ConsoleApplication10.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include<iostream>
using namespace std;
class A
{
	int x;
public:
	A()
	{
		cout << "Constructor A 运行函数 第一个构造函数" << endl;
		x = 1;

	}
	A(int a)//a2
	{
		cout << "constructor A 第二个构造函数" << endl;
		x = a;

	}
	~A()
	{
		cout << " 析构函数 A " << endl;

	}

	void Show()
	{

		cout << "x=：" << x << endl;
	}
};
int main()
{
	A a1, a2(5);//a1 是默认构造函数 
	a1.Show();//这个第二个虚构
	a2.Show();//这个函数先析构
    return 0;
}

