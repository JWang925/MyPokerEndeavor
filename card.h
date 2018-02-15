#pragma once
#include <iostream>


class Card {
public:
	Card(); //default constructor
	Card(int rank, int suit); //construct by giving a suit and rank
	~Card(); //destructor
	int GetSuit();
	int GetRank();

private:
	int  _rank, _suit;

};

std::ostream& operator<<(std::ostream& outstream, Card c); //output overload

