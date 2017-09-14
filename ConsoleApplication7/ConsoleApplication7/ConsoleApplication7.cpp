// ConsoleApplication6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


/*class A
{
public:
	virtual void act1();
	void act2() { act1(); }
};
void A::act1()
{
	cout << "A::act()called" << endl;
}
class B :public A
{
public:
	void act1();
};
void B::act1()
{
	cout << "B::act()called" << endl;

}
void main()
{
	B b;
	b.act2();
	b.act1();
}*/
/*class A
{
public:
	virtual void print()
	{
		cout << "This is class A printing" << endl;
	}
};
class B :public A
{
public:
	void print()
	{
		cout << "This is class B printing" << endl;

	}
};
class C :public B
{
public:
	void print()
	{
		cout << "This is class C printing" << endl;

	}
};
void Show(A&a)
{
	a.print();

}
void main()
{
	A a;
	B b;
	C c;
	Show(a);
	Show(b);
	Show(c);

}*/
/*
class TPoint
{
	int x, y;
public:
	TPoint(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	friend void Distance(TPoint x, TPoint y);
	
};
void Distance(TPoint x, TPoint y)
{
	double L = 0;
	L = sqrt((x.x - y.x)*(x.x - y.x) + (x.y - y.y)*(x.y - y.y));
		cout << "The distance between two points is :" << L << endl;
}
void main()
{
	TPoint A(2, 3), A1(5, 6);
	Distance(A, A1);

}*/
/*#include "stdio.h"
const double P = 3.14;
class Circle {
public:
	virtual double Area();
	void R(double s);
	double getr();
private:
	double radius;
};
void Circle::R(double r)
{
	radius = r;
}
double Circle::getr()
{
	return radius;
}
double Circle::Area()
{
	return P*radius*radius;
}
class Cylinder :public Circle
{
public:
	Cylinder(double h1);
	double R(double r);
	double Area();
	void A(Circle cc);
private:
	double h;
	double s;
};
Cylinder::Cylinder(double h1)
{
	h = h1;
}
void Cylinder::A(Circle cc)
{
	s = cc.Area() + 2 * P*h*cc.getr();
}

double Cylinder::Area()
{
	return s;
}
void main()
{
	Circle c;
	c.R(1);
	printf("圆的面积为：%0.2f\n", c.Area());
	Cylinder c1(1);
	c1.A(c);
	printf("圆柱体的面积为：%0.2f\n", c1.Area());
}*/
const double P = 3.14159;
class TCircle
{
private:
	int x, y;
	double radius;
public:
	TCircle(int x, int y, double r)
	{
		x = x;
		y = y;
		radius = r;
	}
	virtual void Area()
	{
		double S;
		S = P*radius*radius;
		cout << "The S of circle is :" << S << endl;
	}
};
class TCylinder :public TCircle
{
public:
	TCylinder(double h1, int x, int y, double r);
	void Area();
	void ShowV();
private:
	double h;
	double s;
	int x, y;
	double radius;
};
TCylinder::TCylinder(double h1,  int x, int y, double r):TCircle(x,  y,  r)
{
	h = h1;
	x = x;
	y = y;
	radius = r;
}

void TCylinder::Area()
{
	s = P*radius*radius * 2 + 2 * P*h;
	cout<<"The area of the cylinder is " <<s<<endl;
}
void TCylinder::ShowV()
{
	cout << "The V of the cylinder is " << P*radius*radius*h<< endl;
}
void main()
{
	TCircle A(1, 2, 9);
	A.Area();
	TCylinder A1(2, 3, 4, 10);
	A1.Area();
	A1.ShowV();
}