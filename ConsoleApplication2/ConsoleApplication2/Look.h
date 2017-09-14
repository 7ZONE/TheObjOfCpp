#ifndef ______LOOK__H
#define ______LOOK__H

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include"Card.h"
#include "Look.h"
using namespace std;
void P_P()
{
	Deck A;
	char c, d;
	int m = 1, sum1 = 0, sum2 = 0;
	cout << "\n-----------------------------------------------------------------------\n";
	cout << "                                   PVP                                 \n\n";
	A.shuffle();
	do {
		cout << "���1��ѡ���Ƿ�Ҫ�ƣ�(Y/N): ";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			A.deal(m);
			sum1 = A.Find_n(m) + sum1;
			if (sum1>21)
			{
				break;
			}
			m = m + 1;
		}
		cout << "���2��ѡ���Ƿ�Ҫ�ƣ�(Y/N): ";
		cin >> d;
		if (d == 'Y' || d == 'y')
		{
			A.deal(m);
			sum2 = A.Find_n(m) + sum2;
			if (sum2>21)
			{
				break;
			}
			m = m + 1;
		}
	} while ((c == 'Y' || c == 'y') || (d == 'Y' || d == 'y'));
	cout << "���һ�ķ���Ϊ " << sum1 << endl;
	cout << "��Ҷ��ķ���Ϊ " << sum2 << endl;
	if (sum2>21)
	{
		cout << "���һʤ����\n";
	}
	else if (sum1>21)
	{
		cout << "��Ҷ�ʤ����\n";
	}
	else if (sum1>sum2)
	{
		cout << "���һʤ����\n";
	}
	else if (sum1<sum2)
	{
		cout << "��Ҷ�ʤ����\n";
	}
	else if (sum1 == sum2)
	{
		cout << "ƽ�֣�";
	}
}
void P_E()
{
	srand((int)time(NULL));
	Deck A;
	char c;
	int m = 1, sum1 = 0, sum2 = 0, d = 0;
	cout << "\n-----------------------------------------------------------------------\n";
	cout << "                                   PVE                                 \n\n";
	A.shuffle();
	do {
		cout << "���1��ѡ���Ƿ�Ҫ�ƣ�(Y/N): ";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			A.deal(m);
			sum1 = A.Find_n(m) + sum1;
			if (sum1 > 21)
			{
				break;
			}
			m = m + 1;
		}
		d = 1 + rand() % 2;
		if (d == 1)
		{
			cout << "����Ҫ��\n";
			A.deal(m);
			sum2 = A.Find_n(m) + sum2;
			if (sum2 > 21)
			{
				break;
			}
			m = m + 1;
		}
		else
		{
			cout << "���Բ�Ҫ\n";
		}
	} while ((c == 'Y' || c == 'y') || d == 1);
	cout << "���һ�ķ���Ϊ " << sum1 << endl;
	cout << "���Եķ���Ϊ " << sum2 << endl;
	if (sum2 > 21)
	{
		cout << "���һʤ����\n";
	}
	else if (sum1 > 21)
	{
		cout << "����ʤ����\n";
	}
	else if (sum1 > sum2)
	{
		cout << "���һʤ����\n";
	}
	else if (sum1 < sum2)
	{
		cout << "��Ҷ�ʤ����\n";
	}
	else if (sum1 == sum2)
	{
		cout << "ƽ�֣�";
	}
}
#endif