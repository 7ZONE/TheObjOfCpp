// ThePracticeOfPolymorphism.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include "alltheclass.h"
using namespace std; 


int main()
{
	TwoDimShape *shape1 = new CTriange();
	shape1->showDate();
	shape1->reArea(); TwoDimShape *shape2 = new CRect();
	delete shape1;
	shape2->showDate();
	shape2->reArea(); TwoDimShape *shape3 = new CCircle();
	delete shape2;
	shape3->showDate();
	shape3->reArea();
	delete shape3;


	TwoDimShape *shape4 = new Elipse();
	shape4->showDate();
	shape4->reArea(); 
	delete shape4;

	ThreeShape *shape5 = new Ball();
	shape5->showDate();
	shape5->reVolume(); 
	delete shape5;

	ThreeShape *shape6 = new Cylinder();
	shape6->showDate();
	shape6->reVolume(); 
	delete shape6;

	ThreeShape *shape7 = new RectangularParallelepiped();
	shape7->showDate();
	shape7->reVolume();
	delete shape7;
	cout << "�����Ѿ�ȫ��ʵ�֣���������˳�����" << endl;
	getchar();
	return 0;
}

