
#ifndef Assistente___H__
#define Assistente___H__
#include "stdafx.h"
#include <iostream>
#include <string>
#include "PersonInSchool.h"
#include "Student.h"
#include "teacher.h"
#include "Assistente.h"

using namespace std;

class TAssistente:public TStudent,public TTeacher
{

public:
	TAssistente( string name1, string sex1, string dateofBorn1, string place1, int ID1, int StudentID1, string Major1, int ClassNum1, int LessonHours1)
		:TStudent( name1,  sex1,  dateofBorn1,  place1,  ID1,  StudentID1,  Major1,  ClassNum1,  LessonHours1)
	{
		name = name1;
		sex = sex1;
		dateofBorn = dateofBorn1;
		place = place1;
		ID = ID1;
		StudentID = StudentID1;
		Major = Major1;
		ClassNum = ClassNum1;
		LessonHours = LessonHours1;
	}
	TAssistente(string name1, string sex1, string dateofBorn1, string place1, int ID1, string Lesson1, int LessonHours1, int TeacherID1)
		:TTeacher( name1, sex1, dateofBorn1, place1, ID1, Lesson1, LessonHours1,  TeacherID1)
	{
		name = name1;
		sex = sex1;
		dateofBorn = dateofBorn1;
		place = place1;
		ID = ID1;
		Lesson = Lesson1;
		LessonHours = LessonHours1;
		TeacherID = TeacherID1;

	}
	void Show()
	{
		cout << "学生姓名：" << name<< endl;
		cout << "学生性别：" << sex<< endl;
		cout << "身份证号码：" << ID<< endl;
		cout << "出生时间：" << dateofBorn << endl;
		cout << "出生地点：" << place<< endl;
		cout << "学生ID：" << StudentID << endl;
		cout << "学生班级：" << ClassNum<< endl;
		cout << "学生专业：" << Major << endl;
		cout << "学生课时：" << LessonHours<< endl;

	}
	void Show1()
	{
		cout << "教师姓名：" << name << endl;
		cout << "教师性别：" << sex << endl;
		cout << "身份证号码：" << ID<< endl;
		cout << "出生时间：" << dateofBorn << endl;
		cout << "出生地点：" << place<< endl;
		cout << "教师ID：" << TeacherID << endl;
		cout << "授课科目：" << Lesson << endl;
		cout << "授课课时：" << LessonHours << endl;
	}
	~TAssistente() {}

	
	int StudentID;
	int TeacherID;
	int ClassNum;
	int LessonHours;
	string Lesson;
	string Major;
	string name;
	string sex;
	string dateofBorn;
	string place;
	int ID;
};


#endif // !TEACHER___H__



