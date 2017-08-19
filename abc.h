#pragma once
#include <vector>

class PokerHand {
public:
  int handmap[5][15]= { {0}};
  PokerHand (const char* pokerhand) ; //constructor from char input
  PokerHand (const int ); //constructor by defining number of random cards
  ~PokerHand (); //destructor
};



enum class Result { Win, Loss, Tie };

std::ostream& operator<<(std::ostream& o, Result R); //output overload



bool _is_SF(const int handmap[][15], std::vector<int> &);
bool _is_quad(const int handmap[][15], std::vector<int>&);
bool _is_FH(const int handmap[][15], std::vector<int> &);
bool _is_flush(const int handmap[][15], std::vector<int>&);
bool _is_straight(const  int handmap[][15],std::vector<int>&);
bool _is_three_of_a_kind(const int handmap[][15], std::vector<int> &);
bool _is_two_pairs(const int handmap[][15], std::vector<int> &);
bool _is_one_pair(const int handmap[][15], std::vector<int> &);
void _high_cards(const int handmap[][15], std::vector<int> &);
Result compareV(const std::vector<int> &, const std::vector<int> &);
Result compare (const PokerHand &, const PokerHand &);
