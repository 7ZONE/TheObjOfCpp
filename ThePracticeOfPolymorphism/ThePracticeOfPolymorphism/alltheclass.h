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
	float floor;//�ױ߳���
	float higth;//��
public:
	void showDate();
	void reArea();
	virtual ~CTriange() {}
};
class CRect :public TwoDimShape
{
	float lenth;//��
	float wide;//��
public:
	void showDate();
	void reArea();
	
	virtual ~CRect() {  }

};
class CCircle :public TwoDimShape
{
	float radius; //Բ�İ뾶
public:
	void showDate();
	void reArea();
	virtual ~CCircle() { }

};
class Elipse :public TwoDimShape
{
	float x; //��Բ�ĳ���
	float y; //��Բ�Ķ���
public:
	void showDate();
	void reArea();

	virtual ~Elipse() { }

};
class Cylinder :public ThreeShape
{
	float b; //Բ����İ뾶
	float c; //Բ����ĸ�
public:
	void showDate();
	void reVolume();
	virtual ~Cylinder() { }

};
class RectangularParallelepiped :public ThreeShape
{
	float d; //������ĳ�
	float e; //������Ŀ�
	float f; //������ĸ�
public:
	void showDate();
	void reVolume();

	virtual ~RectangularParallelepiped() { }

};
class Ball :public ThreeShape
{
	float a; //��İ뾶
public:
	void showDate();
	void reVolume();

	virtual ~Ball() { }

};
#endif // !ALLTHECLASS__H__
