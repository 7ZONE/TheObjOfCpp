// TheHeranceOfBuilding.cpp : �������̨Ӧ�ó������ڵ㡣
/*
Programing : Practice of inherance
Author: ֣־ǿ
Date:2017-5-29
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Building.h"
using namespace std;


int main()
{


	Building* b1 = new House("Kunming University of Science and Technology", 10, 500.0,5,5);
	b1->Print();
	Building* b2 = new Office("The Office of World", 5, 100.0,6,8);
	b2->Print();
	delete b1;
	delete b2;
    return 0;
}

