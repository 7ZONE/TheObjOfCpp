// TheInheranceOfSchool.cpp : 定义控制台应用程序的入口点。
/*计下图所示的学校师生类层次结构。第一层“在校人员”类的数据成员包括姓名、性别、出生日期、出生地和身份证号码。
由“在校人员”类派生“学生类”和“教师类”。学生类的数据成员有学号、专业、班级和每周学时数。
教师类的数据成员有工作证号、职称、课程和每周课时。
助教类继承学生类和教师类，可以用学生类的全部数据成员，以及教师类的课程和每周课时数据成员。
每个类提供自定义的构造函数和析构函数，定义一组公有成员函数分别用于置各数据成员的值和返回数据成员的值。
建立类体系时，应仔细考虑各类的继承特性，成员的访问特性。请编写主函数测试这个类体系。*/
/*
Programing : Practice of inherance 2
Author: 郑志强
Date:2017-5-29
*/
#include "stdafx.h"
#include <iostream>
#include "PersonInSchool.h"
#include "Student.h"
#include "teacher.h"
#include "Assistente.h"
#include <string>
using namespace std;


int main()
{

	TAssistente *p = new TAssistente("lixiao","男","2017-5-29","kunming",2017052901,"英语和美术",60,9527);
	p->Show1();
	p = new TAssistente("刘梦","Girl","2017-5-30","巫家坝",5301111999999,123456,"学前教育",10,50);
	p->Show();
    return 0;
}


