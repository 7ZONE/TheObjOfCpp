#pragma once
#ifndef __PERSON_IN_
#define __PERSON_IN_
#include "stdafx.h"
#include <iostream>
#include <string>
#include "PersonInSchool.h"
using namespace std;
class TPersonIn
{
	

public:
	TPersonIn() {}
	TPersonIn(string name1, string sex1, string dateofBorn1, string place1, int ID1)
	{
		name = name1;
		sex = sex1;
		dateofBorn = dateofBorn1;
		place = place1;
		ID = ID1;
	}
	virtual ~TPersonIn() {}
	virtual void Show() = 0;
	string name;
	string sex;
	string dateofBorn;
	string place;
	int ID;

};
using namespace std;
#endif // !__PERSON_IN_
