// ConsoleApplication8.cpp : 定义控制台应用程序的入口点。
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
	friend void Distance(TPoint P1, TPoint P2);//P1里面包含了它自己的x y,p2也是。
	
	
};
 void Distance(TPoint P1, TPoint P2)//P1里面包含了它自己的x y,p2也是。
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