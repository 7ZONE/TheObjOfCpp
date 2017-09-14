#pragma once
#ifndef ___CARD__H
#define ___CARD__H
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include"Card.h"
using namespace std;
class Deck;
const int Num = 52;
enum Suit { Diamonds, Cluds, Hearts, Spades };
enum Face { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
class Deck {
private:
	int n, m, k;
	int deck[Num], r_deck[Num];
public:
	Deck()
	{
		for (n = 1; n <= Num; n++)
		{
			deck[n] = n;
			r_deck[n] = 0;
		}
	}
	void Card(int n);
	int Find_n(int m);
	void shuffle();
	void deal(int m);
};


#endif // !___CARD__H
