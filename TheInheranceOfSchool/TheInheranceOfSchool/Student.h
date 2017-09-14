

#ifndef STUEDNT__H__
#define STUEDNT__H__
#include "stdafx.h"
#include <iostream>
#include <string>
#include "PersonInSchool.h"
#include "Student.h"
using namespace std;
 
class TStudent:public TPersonIn
{

public:
	TStudent(){}
	TStudent(string name1, string sex1, string dateofBorn1, string place1, int ID1,int StudentID1, string Major1, int ClassNum1, int LessonHours1 )
		:TPersonIn(name1, sex1, dateofBorn1, place1, ID1)
	{
		StudentID = StudentID1;
		Major = Major1;
		ClassNum = ClassNum1;
		LessonHours = LessonHours1;

	}
	~TStudent(){}
	int StudentID;
	string Major;
	int ClassNum;
	int LessonHours;
};


#endif // !STUEDNT__H__


