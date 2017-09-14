#include "stdafx.h"
#include <iostream>
#include <time.h>
#include"Card.h"
using namespace std;
void Deck::Card(int n)
{
	if (n / 13 == Diamonds)
	{
		cout << deck[n] << ":diamonds_";
	}
	else if (n / 13 == Cluds)
	{
		cout << deck[n] << ":Cluds_";
	}
	else if (n / 13 == Hearts)
	{
		cout << deck[n] << ":hearts_";
	}
	else
	{
		cout << deck[n] << ":spades_";
	}
	switch (n % 13) {
	case Ace:
	{
		cout << "Ace_1\n";
		break;
	}
	case Two:
	{
		cout << "Two_2\n";
		break;
	}
	case Three:
	{
		cout << "Three_3\n";
		break;
	}
	case Four:
	{
		cout << "Four_4\n";
		break;
	}
	case Five:
	{
		cout << "Five_5\n";
		break;
	}
	case Six:
	{
		cout << "Six_6\n";
		break;
	}
	case Seven:
	{
		cout << "Seven_7\n";
		break;
	}
	case Eight:
	{
		cout << "Eight_8\n";
		break;
	}
	case Nine:
	{
		cout << "Nine_9\n";
		break;
	}
	case Ten:
	{
		cout << "Ten_10\n";
		break;
	}
	case Jack:
	{
		cout << "Jack_J\n";
		break;
	}
	case Queen:
	{
		cout << "Queen_Q\n";
		break;
	}
	case 0:
	{
		cout << "King_K\n";
		break;
	}
	}
}
void Deck::shuffle()
{
	srand((int)time(NULL));
	for (m = 1; m <= Num; m++)
	{
		n = 1 + rand() % Num;
		r_deck[m] = deck[n];
		for (k = 1; k<m; k++)
		{
			if (r_deck[m] == r_deck[k])
			{
				m = m - 1;
				break;
			}
		}

	}

}
void Deck::deal(int m)
{
	for (n = 1; n <= Num; n++)
	{
		if (r_deck[m] == deck[n])
		{
			Card(n);
		}
	}
}
int Deck::Find_n(int m)
{
	int n;
	n = r_deck[m] % 13;
	while (n == 0)
	{
		return 13;
	}
	return n;
}
