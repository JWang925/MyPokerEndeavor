
#include "pokerhand.h"

PokerHand::PokerHand (const int ncard){ //constructor by defining number of random cards, generate a random hand. For example, PokerHand hand1(7);
	int icard=0;
	while(icard<ncard){
		int i=std::rand()%4+1;
		int j=std::rand()%13+1;
		if(handmap[i][j]==1) continue;
		handmap[i][j]=1;
		handmap[0][j]+=1;
		handmap[i][0]+=1;
		++icard;
		if(j==1) {handmap[i][j+13]=1;handmap[0][j+13]++;}
	}
}

PokerHand::PokerHand (const char* pokerhand) { //constructor from a string input such as "KH KD TC 3C"
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
 };


PokerHand::~PokerHand(){}



void PokerHand::print(){
	for (int i=0; i<=4; i++){
		for (int j=0; j<=14; j++)
			std::cout << handmap[i][j] << ' ';
		std::cout<<std::endl;
	}



}


bool PokerHand::_is_SF(std::vector<int> &Kicker){  
	for(int suit=1; suit<=4; suit++){ //go through the suits one-by-one
		if(handmap[suit][0]<5) continue; //if there is less than 5 cards for a suit, skip this suit
		for(int rank=10; rank>=1; rank--){ //if more than 5 cards for a suit, check downwards from T for a SF
			if(handmap[suit][rank]==1 && handmap[suit][rank+1]==1 &&handmap[suit][rank+2]==1 &&handmap[suit][rank+3]==1 && handmap[suit][rank+4]==1){
				Kicker[1]=rank+4;
				Kicker[0]=8; //8 for SF
				return 1;
			}
		}
	}
	return 0;
}


bool PokerHand::_is_quad(std::vector<int> &Kicker){ //this is very straight too; check downwards from Ace for Quads
	for(int rank=14; rank>1; rank--){
		if(handmap[0][rank]==4){
			Kicker[1]=rank;
			for(int rank2=14; rank2>1; rank2--) //rank2 is an "iterator" scanning for the Kicker
      	        		if(handmap[0][rank2]!=0 && rank2!=Kicker[1]){
					Kicker[2]=rank2;
					break;
				}
			Kicker[0]=7; //7 for Quad
    	        	return 1;
		}
	} 
 	return 0;
}

bool PokerHand::_is_FH(std::vector<int> &Kicker){ //check for trips and then check for pair
	for(int rank=14; rank>1; rank--){
		if(handmap[0][rank]==3) {
			Kicker[1]=rank;
			for(int rank2=14; rank2>=2; rank2--){ //then look for the pair
				if(rank2==Kicker[1]) continue;	//well we have to skip the rank which has the trip
				if(handmap[0][rank2]>=2) {
					Kicker[2]=rank2;
					Kicker[0]=6; //6 for FH
					return 1;
				}   
			}
		}
	}
	return 0;
}


bool PokerHand::_is_flush(std::vector<int> &Kicker){
	int suit;
	auto it=Kicker.begin();
	it++;
	for(suit=1; suit<=4; suit++) //go through the suits and look if the suit has 5 cards, if so, go ahead and assume it is not possible to have 2 Flushes in a hand. (need to check that the pokerhand size <10)
		if(handmap[suit][0]>=5) break;
	if (suit==5) { return 0;} //return 0 when no flush is found
	for (int High_card=14; High_card>=2; High_card--){ //now we have high cards, count downwards
		if(handmap[suit][High_card]==1 && it!=Kicker.end()){ //stop when the vector <Kicker> is fully filled
			(*it) =High_card;
			it++;
		}
	}
	Kicker[0]=5; //5 for Flush
	return 1;
}


bool PokerHand::_is_straight(std::vector<int> &Kicker){ //this is straight forward: check the numbers
	for(int rank=1; rank<=10; rank++){
		if(handmap[0][rank] != 0 && handmap[0][rank+1] != 0 && handmap[0][rank+2] != 0 && handmap[0][rank+3] !=0 && handmap[0][rank+4] !=0){
			Kicker[1]=rank+4;
			Kicker[0]=4; //4 for straight
			return 1;
		}
	}
	return 0;
}


bool PokerHand::_is_three_of_a_kind(std::vector<int> &Kicker){ //check for trips
	auto it=Kicker.begin();
	it++;
	for(int rank=14; rank>=2; rank--){ //find the three_of_a_kind
		if(handmap[0][rank]==3) {
			(*it)=rank;it++;
			for(int rank2=14; rank2>1; rank2--){ //collect the kickers
				if(handmap[0][rank2]==1 && rank2!=rank && it!=Kicker.end()) {(*it)=rank2; it++;}
			}
		Kicker[0]=3; //3 for trip
		return 1;
		}
	}
	return 0;
}

bool PokerHand::_is_two_pairs(std::vector<int> &Kicker){
	auto it=Kicker.begin();
	it++;
	for(int rank=14; rank>=2; rank--){ //find 2 pairs.
		if(handmap[0][rank]==2) { //find first pair
			(*it)=rank;it++;
			for(int rank2=rank-1; rank2>=2; rank2--){
				if(handmap[0][rank2]==2){//find second pair
					(*it)=rank; it++;
					for(int rank3=14; rank3>=2; rank3--){ //find the kicker
						if(handmap[0][rank3]>0 && rank3 !=rank2 && rank3!=rank){
							(*it)=rank3;
							Kicker[0]=2; //2 for two pairs 
							return 1;
						}
					} 
				}
			}
		}
	}
    return 0;
}

bool PokerHand::_is_one_pair(std::vector<int> &Kicker){
	auto it=Kicker.begin();
	it++;
	for(int rank=14; rank>=2; rank--){ //Starting from Ace(14), looking for a pair one-by-one downwards
		if(handmap[0][rank]==2) { //found first pair
			(*it)=rank;it++; //document it!
			for(int rank2=14; rank2>=2; rank2--){ //now start to record the kickers, again downward from Ace (14).
				if(handmap[0][rank2]==1 && it!=Kicker.end()){
					(*it)=rank2; it++; 
				}
			}
		Kicker[0]=1; //1 for one pair;
		return 1;
		}
	}
	return 0;
}

void PokerHand::_high_cards(std::vector<int> &Kicker){
	auto it=Kicker.begin();
	it++;
	for(int rank=14; rank>=2; rank--){
		if(handmap[0][rank]==1 && it!=Kicker.end()) {  (*it)=rank;it++; }
	}
}


