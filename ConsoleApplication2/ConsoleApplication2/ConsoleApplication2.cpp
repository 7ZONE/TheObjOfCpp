#include "stdafx.h"
#include <iostream>
#include <time.h>
#include"Card.h"
#include "Look.h"
using namespace std;


int main(){
	int a;
	cout << "-----------------------------------------------------------------------\n";
	cout << "                               二十一点                                 \n";
	cout << "-----------------------------------------------------------------------\n\n";
	cout << "-------------------------1:      pvp       ----------------------------\n";
	cout << "-------------------------2:      pve       ----------------------------\n\n";
	cout << "-----------------------------------------------------------------------\n";
	cout << endl << "你想玩哪种？ (1 or 2): ";
	cin >> a;
	if (a == 1)
	{
		P_P();

	}
	else if (a == 2)
	{
		P_E();
	}
	else
	{
		cout << "错误";
	}
	cout << "-----------------------------------------------------------------------\n";
	cout << "游戏结束\n";
	return 0;
}