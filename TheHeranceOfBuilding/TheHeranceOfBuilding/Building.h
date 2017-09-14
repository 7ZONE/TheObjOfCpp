#pragma once
#ifndef  __BUILDING_H
#define  __BUILDING_H
#include"stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Building
{
public:
	Building()
	{}
	Building(string name1, int floors1, double areas1);
	virtual void Print() = 0;
	virtual ~Building() {}
protected:
	string name;
	int floors;
	double areas;
};

class House :public Building
{
public:
	House(string name1, int floors1, double areas1, int rooms1, int balcony1);
	
	void Print();

	~House() {}
private:
	int rooms;
	int balcony;
};
class Office :public Building
{
public:
	Office(string name1, int floors1, double areas1, int offices1, int meetingrooms1) ;
	void Print();
	
	~Office() {}
private:
	int offices;
	int meetingrooms;
};
#endif // ! __BUILDING_H
