#pragma once
#include <iostream>


class Card {
public:
	Card(); //default constructor
	Card(int rank, int suit); //construct by giving a rank then suit; Rank: {1:A 2:2 ...10:T 11:J 12:Q 13:K} Suit: {1:S 2:H 3:C 4:D} for example Card acard(1,4) for Ace of Diamond
	~Card(); //destructor
	int GetSuit();
	int GetRank();

private:
	int  _rank, _suit;

};

std::ostream& operator<<(std::ostream& outstream, Card c); //output overload

