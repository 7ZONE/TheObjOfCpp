// ConsoleApplication6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*class A
{
protected:
	int x;
public:
	A(int x)
	{
		A::x = x;
		cout << "class A" << endl;
	}
};

class B
{
	A a1;

public:
	B(int x):a1(x)
	{
		
		cout << "class B" << endl;
	}
};

class C:public B
{
	A a2;
public:
	C(int x) :B(x),a2(x)
	{

		cout << "class C" << endl;
	}
};
class D :public C
{
public:
	D(int x) :C(x)
	{

		cout << "class D" << endl;
	}
};

int main()
{
	D the1(10);

  return 0;
}*/
class A
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
}