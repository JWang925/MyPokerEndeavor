#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

class PokerHand {
public:

	PokerHand(); //default constructor

	PokerHand (const char* pokerhand) ; //constructor from char input: for example: PokerHand hand1("2H 3H 4H 5H 6D 7H 8H");

	PokerHand (const int ); //constructor by defining number of random cards, generate a random hand. For example, PokerHand hand1(7);

	~PokerHand (); //destructor

	//void add (const card );

	int handmap[5][15]= {{0}}; //an 2D array initialized to zero, unfortunately I have to leave it to public to speed up computational time

	bool _is_SF(const int handmap[][15], std::vector<int> &);
	bool _is_quad(const int handmap[][15], std::vector<int>&);
	bool _is_FH(const int handmap[][15], std::vector<int> &);
	bool _is_flush(const int handmap[][15], std::vector<int>&);
	bool _is_straight(const  int handmap[][15],std::vector<int>&);
	bool _is_three_of_a_kind(const int handmap[][15], std::vector<int> &);
	bool _is_two_pairs(const int handmap[][15], std::vector<int> &);
	bool _is_one_pair(const int handmap[][15], std::vector<int> &);
	void _high_cards(const int handmap[][15], std::vector<int> &);

private:


};


enum class Result { Win, Loss, Tie };

std::ostream& operator<<(std::ostream& o, Result R); //output overload



Result compareV(const std::vector<int> &, const std::vector<int> &);
Result compare (const PokerHand &, const PokerHand &);
