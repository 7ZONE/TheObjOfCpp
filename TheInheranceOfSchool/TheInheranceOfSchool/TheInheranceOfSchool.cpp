// TheInheranceOfSchool.cpp : �������̨Ӧ�ó������ڵ㡣
/*����ͼ��ʾ��ѧУʦ�����νṹ����һ�㡰��У��Ա��������ݳ�Ա�����������Ա𡢳������ڡ������غ����֤���롣
�ɡ���У��Ա����������ѧ���ࡱ�͡���ʦ�ࡱ��ѧ��������ݳ�Ա��ѧ�š�רҵ���༶��ÿ��ѧʱ����
��ʦ������ݳ�Ա�й���֤�š�ְ�ơ��γ̺�ÿ�ܿ�ʱ��
������̳�ѧ����ͽ�ʦ�࣬������ѧ�����ȫ�����ݳ�Ա���Լ���ʦ��Ŀγ̺�ÿ�ܿ�ʱ���ݳ�Ա��
ÿ�����ṩ�Զ���Ĺ��캯������������������һ�鹫�г�Ա�����ֱ������ø����ݳ�Ա��ֵ�ͷ������ݳ�Ա��ֵ��
��������ϵʱ��Ӧ��ϸ���Ǹ���ļ̳����ԣ���Ա�ķ������ԡ����д�����������������ϵ��*/
/*
Programing : Practice of inherance 2
Author: ֣־ǿ
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

	TAssistente *p = new TAssistente("lixiao","��","2017-5-29","kunming",2017052901,"Ӣ�������",60,9527);
	p->Show1();
	p = new TAssistente("����","Girl","2017-5-30","�׼Ұ�",5301111999999,123456,"ѧǰ����",10,50);
	p->Show();
    return 0;
}


