#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "card.h"

class PokerHand {
public:
	PokerHand(); //default constructor

	PokerHand (const char* pokerhand) ; //constructor from char input: for example: PokerHand hand1("2H 3H 4H 5H 6D 7H 8H");

	PokerHand (const int ); //constructor by defining number of random cards, generate a random hand. For example, PokerHand hand1(7);

	~PokerHand (); //destructor

	//void add (const Card & ); //add a card to the card map
	
	void print();


	//check if hand is SF, return a vector of length 6 signifying [hand type,kicker1,kicker2,kicker3,kicker4,kicker5]
	//strength 8=SF; 7=Quad; 6=Full House; 5=Flush 4=Straight 3=trip 2=twopairs 1=onepair 0=highcard
	bool _is_SF(std::vector<int> &); 
	bool _is_quad(std::vector<int>&); 
	bool _is_FH(std::vector<int> &);
	bool _is_flush(std::vector<int>&);
	bool _is_straight(std::vector<int>&);
	bool _is_three_of_a_kind(std::vector<int> &);
	bool _is_two_pairs(std::vector<int> &);
	bool _is_one_pair(std::vector<int> &);
	void _high_cards(std::vector<int> &);

private:
	int handmap[5][15]= {{0}}; //an 2D array initialized to zero,  leave it to public to speed up computational time (? need to check)
};
