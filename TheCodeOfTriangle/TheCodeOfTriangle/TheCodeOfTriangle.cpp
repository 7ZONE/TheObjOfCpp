// TheCodeOfTriangle.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j <=i;j++)
		{
			cout << "*" ;
		}
		cout << endl;
	}
	for (int i = 0;i < 4;i++)
	{
		for (int m = 3;m > i;m--)
		{
			cout << " ";
		}
		for (int j = 0;j <= i;j++)
		{
			cout << "*";
		}
		cout << endl;
	}
    return 0;
}

