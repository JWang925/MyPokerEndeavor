#include <vector>

struct PokerHand {
        int handmap[5][15]= { {0}};

  PokerHand (const char* pokerhand) {
        int i,j;
    while (*pokerhand != '\0'){
        if( (*pokerhand)==' ') {pokerhand++; continue;}
      switch(*pokerhand){
       case 'K' : i=13; break;
       case 'Q' : i=12; break;
       case 'J' : i=11; break;
       case 'T' : i=10; break;
       case '9' : i=9 ; break;
       case '8' : i=8 ; break;
       case '7' : i=7 ; break;
       case '6' : i=6 ; break;
       case '5' : i=5 ; break;
       case '4' : i=4 ; break;
       case '3' : i=3 ; break;
       case '2' : i=2 ; break;
       case 'A' : i=1 ; break;
       default : std::cout<< "Rank input error!" << std::endl;
      }
     pokerhand++;
      switch(*pokerhand){
       case 'S' : j=1; break;
       case 'H' : j=2; break;
       case 'C' : j=3; break;
       case 'D' : j=4; break;
       default : std::cout<< "Suit input error!" << std::endl;
      }
      pokerhand++;
      if(i==1) {handmap[j][14]++; handmap[0][14]++;}
      handmap[j][i]++;
      handmap[0][i]++;
      handmap[j][0]++;
      i=0;
      j=0;
    }
  } 
};



enum class Result { Win, Loss, Tie };

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
