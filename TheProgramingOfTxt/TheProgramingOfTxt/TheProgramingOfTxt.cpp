// TheProgramingOfTxt.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
Programing : FILE
DATE : 2017-5-30
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string word = "We are the world!";
	int word_count = 1;
	char s;
	ofstream out;
	out.open("TheBest1.txt");
	out << word << endl;
	out.close();
	ifstream in("TheBest1.txt");//open the input file
	if (in.fail())
	{
		cerr << "open failure on file.bat" << endl;
		return 1;
	}
	while (in >> word)
	{
		cout << word << endl;
		word_count++;
	}
	
	int line_number = 0;

	while (in.get(s))
	{
	
		if (s == '\n')
			line_number++;

	}

	

	in.close();

	cout << "�ַ�����" << word_count - 1 << endl;
	cout << "������" << line_number +1<< endl;
    return 0;
}

