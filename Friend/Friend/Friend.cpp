//progaming:geometry
//ahthor:������
//data��2017-4-30

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
	cout << "�ܳ�Ϊ��" << c << endl;
	cout << "���Ϊ��" << s << endl;
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
	cout << "�ܳ�Ϊ��" << d << endl;
	cout << "���Ϊ��" << s << endl;
	cout << "�߳��ֱ�Ϊ��" << a << "," << b << "," << c << endl;
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
	cout << "�ܳ�Ϊ��" << c1 << endl;
	cout << "���Ϊ��" << s << endl;
	cout << "�߳��ֱ�Ϊ��" << a << "," << b << "," << c << "," << d << endl;
}



int main()
{
	int r, a1, b1, c1, a2, b2, c2, d2;
	cout << "����Բ�İ뾶r:" << endl;
	cin >> r;
	circle(r);
	cout << "���������ε�����a1,b1,c1:" << endl;
	cin >> a1 >> b1 >> c1;
	triangle(a1, b1, c1);
	cout << "�����ı��ε�������a2,b2,c2,d2:" << endl;
	cin >> a2 >> b2 >> c2 >> d2;
	quadrilateral(a2, b2, c2, d2);
	return 0;
}


