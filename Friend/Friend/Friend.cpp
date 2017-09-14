//progaming:geometry
//ahthor:付怀金
//data：2017-4-30

#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;


class Tcircle
{
public:
	void friend circle(int r);
};
void circle(int r)
{
	double c, s;
	c = 2 * 3.14159*r;
	s = 3.14159*r*r;
	cout << "周长为：" << c << endl;
	cout << "面积为：" << s << endl;
}

class Ttriangle
{
public:
	void friend triangle(int a, int b, int c);
};
void triangle(int a, int b, int c)
{
	float s, p;
	int d;
	d = a + b + c;
	p = (float)d / 2;
	s = sqrt(p*(p - a)*(p - b)*(p - c));
	cout << "周长为：" << d << endl;
	cout << "面积为：" << s << endl;
	cout << "边长分别为：" << a << "," << b << "," << c << endl;
}


class Tquadrilateral
{
public:
	void friend quadrilateral(int a, int b, int c, int d);
};
void quadrilateral(int a, int b, int c, int d)
{
	float s, p;
	int c1;
	c1 = a + b + c + d;
	p = (float)c1 / 2;
	s = sqrt((p - a)*(p - b)*(p - c)*(p - d));
	cout << "周长为：" << c1 << endl;
	cout << "面积为：" << s << endl;
	cout << "边长分别为：" << a << "," << b << "," << c << "," << d << endl;
}



int main()
{
	int r, a1, b1, c1, a2, b2, c2, d2;
	cout << "输入圆的半径r:" << endl;
	cin >> r;
	circle(r);
	cout << "输入三角形的三边a1,b1,c1:" << endl;
	cin >> a1 >> b1 >> c1;
	triangle(a1, b1, c1);
	cout << "输入四边形的四条边a2,b2,c2,d2:" << endl;
	cin >> a2 >> b2 >> c2 >> d2;
	quadrilateral(a2, b2, c2, d2);
	return 0;
}


