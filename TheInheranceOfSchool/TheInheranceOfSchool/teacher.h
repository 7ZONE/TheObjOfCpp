
#ifndef TEACHER___H__
#define TEACHER___H__
#include "stdafx.h"
#include <iostream>
#include <string>
#include "PersonInSchool.h"
#include "Student.h"
#include "teacher.h"

using namespace std;

class TTeacher:public TPersonIn
{

public:
	TTeacher(){}
	TTeacher(  string name1, string sex1, string dateofBorn1, string place1, int ID1, string Lesson1, int LessonHours1,int TeacherID1)
		:TPersonIn(name1, sex1, dateofBorn1, place1, ID1)
	{
		Lesson = Lesson1;
		LessonHours = LessonHours1;
		TeacherID = TeacherID1;
	}
	TTeacher(int TeacherID1, string Titulo1, string Lesson1, int LessonHours1)
	{
		TeacherID = TeacherID1;
		Titulo = Titulo1;
		Lesson = Lesson1;
		LessonHours = LessonHours1;

	}
	~TTeacher(){}
	string Lesson;
	int LessonHours;
private:
	string Titulo;
	int TeacherID;

	
};


#endif // !TEACHER___H__


