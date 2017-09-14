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
		cout << "玩家1请选择是否要牌？(Y/N): ";
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
		cout << "玩家2请选择是否要牌？(Y/N): ";
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
	cout << "玩家一的分数为 " << sum1 << endl;
	cout << "玩家二的分数为 " << sum2 << endl;
	if (sum2>21)
	{
		cout << "玩家一胜利！\n";
	}
	else if (sum1>21)
	{
		cout << "玩家二胜利！\n";
	}
	else if (sum1>sum2)
	{
		cout << "玩家一胜利！\n";
	}
	else if (sum1<sum2)
	{
		cout << "玩家二胜利！\n";
	}
	else if (sum1 == sum2)
	{
		cout << "平局！";
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
		cout << "玩家1请选择是否要牌？(Y/N): ";
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
			cout << "电脑要牌\n";
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
			cout << "电脑不要\n";
		}
	} while ((c == 'Y' || c == 'y') || d == 1);
	cout << "玩家一的分数为 " << sum1 << endl;
	cout << "电脑的分数为 " << sum2 << endl;
	if (sum2 > 21)
	{
		cout << "玩家一胜利！\n";
	}
	else if (sum1 > 21)
	{
		cout << "电脑胜利！\n";
	}
	else if (sum1 > sum2)
	{
		cout << "玩家一胜利！\n";
	}
	else if (sum1 < sum2)
	{
		cout << "玩家二胜利！\n";
	}
	else if (sum1 == sum2)
	{
		cout << "平局！";
	}
}
#endif