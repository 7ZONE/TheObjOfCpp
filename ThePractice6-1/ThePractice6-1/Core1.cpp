#include "stdafx"
#include<iostream>
using namespace std;
struct hand
{
	int num[1000];
	int head, tail;
}a, b;
int main()
{
	int race = 0;
	a.head = b.head = 1;
	a.tail = 7;b.tail = 7;
	int t[10] = { 0 }, last = 0, card;
	bool book[10] = { 0 };
	for (int i = 1;i <= 6;i++)cin >> a.num[i];
	for (int i = 1;i <= 6;i++)cin >> b.num[i];

	while (a.head<a.tail&&b.head<b.tail)
	{
		race++;
		card = a.num[a.head];
		if (book[card] == 0)
		{
			last++;t[last] = card;
			a.head++;book[card] = 1;
		}
		else
		{
			a.head++;a.num[a.tail] = card;
			a.tail++;
			while (t[last] != card)
			{
				a.num[a.tail] = t[last];
				a.tail++;book[t[last]] = 0;
				last--;
			}
		}

		card = b.num[b.head];
		if (book[card] == 0)
		{
			last++;t[last] = card;
			b.head++;book[card] = 1;
		}
		else
		{
			b.head++;b.num[b.tail] = card;
			b.tail++;
			while (t[last] != card)
			{
				b.num[b.tail] = t[last];
				b.tail++;book[t[last]] = 0;
				last--;
			}
		}
		if (race == 100 && a.head<a.tail&&b.head<b.tail)
		{
			cout << "ƽ��" << endl << "С�ߵ�ǰ���е�����";
			for (int i = a.head;i<a.tail;i++)cout << " " << a.num[i];
			cout << endl << "С����ǰ���е�����";
			for (int i = b.head;i<b.tail;i++)cout << " " << b.num[i];
			if (last>0)
			{
				cout << endl << "���ϵ�����"; for (int i = 1;i <= last;i++)cout << " " << t[i];
			}
			else cout << endl << "�����Ѿ�û������";
		}
	}
	if (a.head<a.tail)
	{
		cout << "С��win" << endl << "С�ߵ�ǰ���е�����";
		for (int i = a.head;i<a.tail;i++)cout << " " << a.num[i];
	}
	else
	{
		cout << "С��win" << endl << "С����ǰ���е�����";
		for (int i = b.head;i<b.tail;i++)cout << " " << b.num[i];
	}
	if (last>0)
	{
		cout << endl << "���ϵ�����"; for (int i = 1;i <= last;i++)cout << " " << t[i];
	}
	else cout << endl << "�����Ѿ�û������";
}