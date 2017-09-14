#include "stdafx.h"
#include <iostream>
using namespace std;
/*class  Myclass
{
	int a, b;
public:
	Myclass(int x = 0, int y = 0);
	~Myclass();

};
Myclass::Myclass(int x, int y) :a(x), b(y)
{
	cout << "This is constructor !a+b=" << a + b << endl;
	cout << " Y 值是" << b << endl;
}
Myclass::~Myclass()
{
	cout << "This is a destructor" << endl;
}
void main()
{
	Myclass x,y(10,20), z(y);
}*/
class A 
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
		cout << "This  is BBB" << endl;
	}
};
class C :public B
{
public:
	void print()
	{
		cout << "This is CCCC " << endl;
	}
};
void Show(A&a)
{
	a.print();
}
void main()
{
	A a;
	B  b;
	C c;
	Show(a);
	Show(b);
	Show(c);
}