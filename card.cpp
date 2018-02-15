#include "card.h"

Card::Card() {
	_suit=0;
	_rank=0;
}

Card::Card(int rank,int suit){
	_suit=suit;
	_rank=rank;
}

Card::~Card(){}

int Card::GetSuit(){
	return _suit;
}

int Card::GetRank(){
	return _rank;
}

std::ostream& operator<<(std::ostream& outstream, Card c){

switch(c.GetRank()){
       		case 1 : outstream<<"A"; break;
       		case 2 : outstream<<"2"; break;
       		case 3 : outstream<<"3"; break;
       		case 4 : outstream<<"4"; break;
       		case 5 : outstream<<"5"; break;
       		case 6 : outstream<<"6"; break;
       		case 7 : outstream<<"7"; break;
       		case 8 : outstream<<"8"; break;
       		case 9 : outstream<<"9"; break;
       		case 10 : outstream<<"T"; break;
       		case 11 : outstream<<"J"; break;
       		case 12 : outstream<<"Q"; break;
		case 13 : outstream<<"K"; break;
       		default : std::cout<< "Rank out of bound!" << std::endl;
}
	
switch(c.GetSuit()){
       		case 1 : outstream<<"s"; break;
       		case 2 : outstream<<"h"; break;
       		case 3 : outstream<<"c"; break;
       		case 4 : outstream<<"d"; break;
       		default : std::cout<< "Suit out of bound!" << std::endl;
}



}
