#ifndef ALLTHECLASS__H__
#define ALLTHECLASS__H__
#include "stdafx.h"
#include <iostream>
#include <string>
#include  "alltheclass.h"
using namespace std;

class Shape
{
public:
	virtual void showData() = 0;
	virtual double reArea() = 0;
	virtual double reVolume() = 0;
	virtual ~Shape() {}

};
class TwoDimShape
{
public:
	virtual void reArea() = 0;
	virtual void showDate() = 0;
	virtual ~TwoDimShape() {}
};
class ThreeShape
{
public:
	virtual void reVolume() = 0;
	virtual void showDate() = 0;
	virtual ~ThreeShape() {}
};
class CTriange :public TwoDimShape
{
	float floor;//底边长度
	float higth;//高
public:
	void showDate();
	void reArea();
	virtual ~CTriange() {}
};
class CRect :public TwoDimShape
{
	float lenth;//长
	float wide;//宽
public:
	void showDate();
	void reArea();
	
	virtual ~CRect() {  }

};
class CCircle :public TwoDimShape
{
	float radius; //圆的半径
public:
	void showDate();
	void reArea();
	virtual ~CCircle() { }

};
class Elipse :public TwoDimShape
{
	float x; //椭圆的长轴
	float y; //椭圆的短轴
public:
	void showDate();
	void reArea();

	virtual ~Elipse() { }

};
class Cylinder :public ThreeShape
{
	float b; //圆柱体的半径
	float c; //圆柱体的高
public:
	void showDate();
	void reVolume();
	virtual ~Cylinder() { }

};
class RectangularParallelepiped :public ThreeShape
{
	float d; //长方体的长
	float e; //长方体的宽
	float f; //长方体的高
public:
	void showDate();
	void reVolume();

	virtual ~RectangularParallelepiped() { }

};
class Ball :public ThreeShape
{
	float a; //球的半径
public:
	void showDate();
	void reVolume();

	virtual ~Ball() { }

};
#endif // !ALLTHECLASS__H__
