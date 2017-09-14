// TheClassOfCircle5-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using  namespace std;
class Circle
{
	int radius;
public:
	Circle(int r)
	{
		radius = r;
	}
	void Output()
	{
		cout << "The radius of the circle is :" << radius << endl;
		cout << "The girth of the circle is :" << 2 * 3.14159*radius << endl;
		cout << "The area of the circle  is :" << 3.15159*radius*radius << endl;
	}
};

int main()
{
	Circle c(5);
	c.Output();
	
    return 0;
}

