// ConsoleApplication8.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class TPoint
{
private:
	int x, y;
public:
//	TPoint(){}
	TPoint(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	void Distance1()
	{
		cout << "X - Y =:" << x - y << endl;
	}
	friend void Distance(TPoint P1, TPoint P2);//P1������������Լ���x y,p2Ҳ�ǡ�
	
	
};
 void Distance(TPoint P1, TPoint P2)//P1������������Լ���x y,p2Ҳ�ǡ�
{
	cout << "The distance between two points  is :" << sqrt((P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y)) << endl;
}


void  main()
{
	TPoint T1(2, 3), T2(9, 8);
	T1.Distance1();
	T2.Distance1();
	Distance(T1, T2);
	
}