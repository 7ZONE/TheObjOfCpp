#include"stdafx.h"
#include <iostream>
#include <string>
#include "Building.h"
using namespace std;
Building::Building(string name1, int floors1, double areas1)
{
	name = name1;
	floors = floors1;
	areas = areas1;
}



	House::House(string name1, int floors1, double areas1, int rooms1, int balcony1) :Building(name1, floors1, areas1)
	{
		rooms = rooms1;
		balcony = balcony1;
	}
	void House::Print()
	{
		cout << "The name of the instruction is :" << name << endl;
		cout << "The number of rooms are:" << rooms << endl;
		cout << "The number of balconys are :" << balcony << endl;
		cout << "The areas is " << areas << endl;
		cout << "The number of floors are:" << floors << endl;

	}



	Office::Office(string name1, int floors1, double areas1, int offices1, int meetingrooms1) :Building(name1, floors1, areas1)
	{
		offices = offices1;
		meetingrooms = meetingrooms1;
	}
	void  Office::Print()
	{
		cout << "The name of the instruction is :" << name << endl;
		cout << "The areas is " << areas << endl;
		cout << "The number of floors are:" << floors << endl;
		cout << "Number of offices :" << offices << endl;
		cout << "The number of meetingrooms :" << meetingrooms << endl;


	}