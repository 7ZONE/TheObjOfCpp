
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
		cout << "ѧ��������" << name<< endl;
		cout << "ѧ���Ա�" << sex<< endl;
		cout << "���֤���룺" << ID<< endl;
		cout << "����ʱ�䣺" << dateofBorn << endl;
		cout << "�����ص㣺" << place<< endl;
		cout << "ѧ��ID��" << StudentID << endl;
		cout << "ѧ���༶��" << ClassNum<< endl;
		cout << "ѧ��רҵ��" << Major << endl;
		cout << "ѧ����ʱ��" << LessonHours<< endl;

	}
	void Show1()
	{
		cout << "��ʦ������" << name << endl;
		cout << "��ʦ�Ա�" << sex << endl;
		cout << "���֤���룺" << ID<< endl;
		cout << "����ʱ�䣺" << dateofBorn << endl;
		cout << "�����ص㣺" << place<< endl;
		cout << "��ʦID��" << TeacherID << endl;
		cout << "�ڿο�Ŀ��" << Lesson << endl;
		cout << "�ڿο�ʱ��" << LessonHours << endl;
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



