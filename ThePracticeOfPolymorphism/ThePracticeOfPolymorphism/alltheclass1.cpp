#include "stdafx.h"
#include <iostream>
#include <string>
#include  "alltheclass.h"
#include  <assert.h>
void CTriange::showDate()
{
	cout << "输入三角形的底和高:" << endl;
	cin >> floor >> higth;
	assert(floor >= 0 && higth >= 0);
}

void CRect::showDate()
{
	cout << "输入矩形的长和宽:" << endl;
	cin >> lenth >> wide;
	assert(lenth >= 0 && wide >= 0);
}

void CCircle::showDate()
{
	cout << "请输入圆的半径：" << endl;
	cin >> radius;
	assert(radius >= 0 );
}

void Elipse::showDate()
{
	cout << "请输入椭圆的长轴跟短轴：" << endl;
	cin >> x >> y;
	assert(x >= 0 && y >= 0);


}
void Ball::showDate()
{
	cout << "请输入球的半径:" << endl;
	cin >> a;
	assert(a >= 0 );

}

void Cylinder::showDate()
{
	cout << "请输入圆柱的半径和高:" << endl;
	cin >> b >> c;
	assert(b >= 0 && c >= 0);

}
void RectangularParallelepiped::showDate()
{
	cout << "请输入长方体的长、宽、高:" << endl;
	cin >> d >> e >> f;
	assert(d>= 0 && e >= 0);
	assert(f>= 0);

}
void CTriange::reArea()
{
	cout << "三角形面积为：" << floor*higth / 2 << endl;
}
void CRect::reArea()
{
	cout << "矩形面积为：" << lenth*wide << endl;
}
void CCircle::reArea()
{
	cout << "圆面积为：" << 3.14*radius*radius << endl;
}
void   Elipse::reArea()
{
	cout << "椭圆面积为：" << 3.14*x*y / 4 << endl;
}
void Cylinder::reVolume()
{
	cout << "圆柱的体积为：" << 3.14*b*b*c << endl;
}
void RectangularParallelepiped::reVolume()
{
	cout << "长方体的体积为：" << d*e*f << endl;
}
void Ball::reVolume()
{
	cout << "球的体积为：" << 4 / 3 * 3.14*a*a*a << endl;
}