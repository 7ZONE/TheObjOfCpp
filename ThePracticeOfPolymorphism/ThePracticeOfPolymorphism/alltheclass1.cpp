#include "stdafx.h"
#include <iostream>
#include <string>
#include  "alltheclass.h"
#include  <assert.h>
void CTriange::showDate()
{
	cout << "���������εĵ׺͸�:" << endl;
	cin >> floor >> higth;
	assert(floor >= 0 && higth >= 0);
}

void CRect::showDate()
{
	cout << "������εĳ��Ϳ�:" << endl;
	cin >> lenth >> wide;
	assert(lenth >= 0 && wide >= 0);
}

void CCircle::showDate()
{
	cout << "������Բ�İ뾶��" << endl;
	cin >> radius;
	assert(radius >= 0 );
}

void Elipse::showDate()
{
	cout << "��������Բ�ĳ�������᣺" << endl;
	cin >> x >> y;
	assert(x >= 0 && y >= 0);


}
void Ball::showDate()
{
	cout << "��������İ뾶:" << endl;
	cin >> a;
	assert(a >= 0 );

}

void Cylinder::showDate()
{
	cout << "������Բ���İ뾶�͸�:" << endl;
	cin >> b >> c;
	assert(b >= 0 && c >= 0);

}
void RectangularParallelepiped::showDate()
{
	cout << "�����볤����ĳ�������:" << endl;
	cin >> d >> e >> f;
	assert(d>= 0 && e >= 0);
	assert(f>= 0);

}
void CTriange::reArea()
{
	cout << "���������Ϊ��" << floor*higth / 2 << endl;
}
void CRect::reArea()
{
	cout << "�������Ϊ��" << lenth*wide << endl;
}
void CCircle::reArea()
{
	cout << "Բ���Ϊ��" << 3.14*radius*radius << endl;
}
void   Elipse::reArea()
{
	cout << "��Բ���Ϊ��" << 3.14*x*y / 4 << endl;
}
void Cylinder::reVolume()
{
	cout << "Բ�������Ϊ��" << 3.14*b*b*c << endl;
}
void RectangularParallelepiped::reVolume()
{
	cout << "����������Ϊ��" << d*e*f << endl;
}
void Ball::reVolume()
{
	cout << "������Ϊ��" << 4 / 3 * 3.14*a*a*a << endl;
}