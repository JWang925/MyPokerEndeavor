
#include "pokerhand.h"

std::ostream& operator<<(std::ostream& outstream, Result R){
    if(R==Result::Win) outstream << "Win" << std::endl;
    if(R==Result::Loss) outstream << "Loss" <<std::endl;
    if(R==Result::Tie) outstream << "Tie" <<std::endl;
}

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




Result compare (const PokerHand &player, const PokerHand &opponent) {
//	for(int j=0; j<5; j++){
//  	    for(int i=0; i<15; i++)
//        std::cout<<player.handmap[j][i];
//        std::cout<<std::endl;
//    }
//    std::cout<<std::endl;
//    for(int j=0; j<5; j++){
//  	    for(int i=0; i<15; i++)
//    	    std::cout<<opponent.handmap[j][i];
//            std::cout<<std::endl;
//    }
  
    std::vector<int>  kickerA(6),kickerB(6);
    while(1){
        if (_is_SF(player.handmap, kickerA)) { 
//			std::cout<<"SF" <<std::endl; 
			kickerA[0]=8;break;}
        if (_is_quad(player.handmap, kickerA)) { 
//			std::cout<<"quad" <<std::endl;
			kickerA[0]=7;break;}
        if (_is_FH(player.handmap, kickerA)) {
//			std::cout<<"FH"<<std::endl; 
			kickerA[0]=6;break;}
        if (_is_flush(player.handmap, kickerA)) {
//			std::cout<<"flush" << std::endl; 
			kickerA[0]=5;break;}
        if (_is_straight(player.handmap, kickerA)) {
//			std::cout<<"straight" << std::endl;
			kickerA[0]=4;break;}
        if (_is_three_of_a_kind(player.handmap, kickerA)) {
//			std::cout<<"3ofakind" <<std::endl;
			kickerA[0]=3;break;}
        if (_is_two_pairs(player.handmap, kickerA)) {
//			std::cout<<"2pairs" <<std::endl; 
			kickerA[0]=2;break;}
        if (_is_one_pair(player.handmap, kickerA)) {
//			std::cout<<"1pair" <<std::endl; 
			kickerA[0]=1;break;}
        _high_cards(player.handmap,kickerA); 
//		std::cout<<"high card"<<std::endl;
		break;
    }
//    std::cout<< "B:";
    while(1){
        if (_is_SF(opponent.handmap, kickerB)) {
//			std::cout<<"SF" <<std::endl; 
			kickerB[0]=8;break;}
        if (_is_quad(opponent.handmap, kickerB)) { 
//			std::cout<<"quad" <<std::endl;
			kickerB[0]=7;break;}
        if (_is_FH(opponent.handmap, kickerB)) {
//			std::cout<<"FH"<<std::endl; 
			kickerB[0]=6;break;}
        if (_is_flush(opponent.handmap, kickerB)) {
//			std::cout<<"flush" << std::endl;
			kickerB[0]=5;break;}
        if (_is_straight(opponent.handmap, kickerB)) {
//			std::cout<<"straight" << std::endl;
			kickerB[0]=4;break;}
        if (_is_three_of_a_kind(opponent.handmap, kickerB)) {
//			std::cout<<"3ofakind" <<std::endl; 
			kickerB[0]=3;break;}
        if (_is_two_pairs(opponent.handmap, kickerB)) {
//			std::cout<<"2pairs" <<std::endl;
			kickerB[0]=2;break;}
        if (_is_one_pair(opponent.handmap, kickerB)) {
//			std::cout<<"1pair" <<std::endl;
			kickerB[0]=1;break;}
        _high_cards(opponent.handmap,kickerB); 
//		std::cout<<"high card"<<std::endl;
		break;
    }
    return compareV(kickerA,kickerB);
}

Result compareV(const std::vector<int> & kickerA, const std::vector<int> & kickerB){
	auto pl=kickerA.begin();
    auto op=kickerB.begin();
    while(pl!=kickerA.end()){
  	    if((*pl)>(*op)) return Result::Win;
  	    if((*pl)<(*op)) return Result::Loss;
  	    pl++;op++;
    }
    return Result::Tie;
}

bool _is_SF(const int handmap[][15], std::vector<int> &Kicker){
	for(int suit=1; suit<=4; suit++){ 
		if(handmap[suit][0]<5) continue; //go check for next suit
		for(int rank=1; rank<=10; rank++){ //check rank
    	    if(handmap[suit][rank]==1 && handmap[suit][rank+1]==1 &&handmap[suit][rank+2]==1 &&handmap[suit][rank+3]==1 && handmap[suit][rank+4]==1){
      	    Kicker[1]=rank+4;
            return 1;
    	    }
        }
    }
  return 0;
}

bool _is_flush(const int handmap[][15], std::vector<int> &Kicker){
	int suit;
    auto it=Kicker.begin();
    it++;
	for(suit=1; suit<=4; suit++)
		if(handmap[suit][0]>=5) break;
	if (suit==5) { return 0;} //return when no flush is found
    for (int High_card=14; High_card>=2; High_card--){
  	    if(handmap[suit][High_card]==1 && it!=Kicker.end()){
    	    (*it) =High_card;
            it++;
        }
    }
    return 1;
}

bool _is_straight(const int handmap[][15], std::vector<int> &Kicker){
	for(int rank=1; rank<=10; rank++){
		if(handmap[0][rank] != 0 && handmap[0][rank+1] != 0 && handmap[0][rank+2] != 0 && handmap[0][rank+3] !=0 && handmap[0][rank+4] !=0){
    	    Kicker[1]=rank+4;
            return 1;
		}
    }
	return 0;
}

bool _is_quad(const int handmap[][15], std::vector<int> &Kicker){
	for(int rank=2; rank<=14; rank++){
  	    if(handmap[0][rank]==4) {
  		    Kicker[1]=rank;
            for(int rank2=14; rank2>1; rank2--)
      	        if(handmap[0][rank2]!=0) Kicker[2]=rank2;
    	        return 1;
        }
    } 
 	return 0;
}

bool _is_FH(const int handmap[][15], std::vector<int> &Kicker){
	for(int rank=14; rank>=2; rank--){
		if(handmap[0][rank]==3) {
			Kicker[1]=rank;
  		    for(int rank2=14; rank2>=2; rank2--){
  			    if(rank2==Kicker[1]) continue;	
				if(handmap[0][rank2]>=2) {
    			    Kicker[2]=rank2;
      		        return 1;
    		    }   
  	        }
        }
	}
	return 0;
}

bool _is_three_of_a_kind(const int handmap[][15], std::vector<int> &Kicker){
	auto it=Kicker.begin();
    it++;
    for(int rank=14; rank>=2; rank--){ //find the three_of_a_kind
  	    if(handmap[0][rank]==3) {
  		    (*it)=rank;it++;
  		    for(int rank2=14; rank2>=2; rank2--){ //collect the kickers
  			    if(handmap[0][rank2]==1 && it!=Kicker.end()) {(*it)=rank2; it++;}
  		    }
        return 1;
  	    }
    }
    return 0;
}

bool _is_two_pairs(const int handmap[][15], std::vector<int> &Kicker){
	auto it=Kicker.begin();
    it++;
    for(int rank=14; rank>=2; rank--){ //find 2 pairs.
		if(handmap[0][rank]==2) { //found first pair
    	    (*it)=rank;it++;
    	    for(int rank2=rank-1; rank2>=2; rank2--){
      	        if(handmap[0][rank2]==2){//found second pair
      		        (*it)=rank; it++;
                    for(int rank3=14; rank3>=2; rank3--){ //find the kicker
          	            if(handmap[0][rank3]==1){
            	            (*it)=rank3; return 1;
                        }
                    } 
                }
            }
        }
    }
    return 0;
}

bool _is_one_pair(const int handmap[][15], std::vector<int> &Kicker){
	auto it=Kicker.begin();
    it++;
    for(int rank=14; rank>=2; rank--){
		if(handmap[0][rank]==2) { //found first pair
    	    (*it)=rank;it++;
            for(int rank2=14; rank2>=2; rank2--){
      	        if(handmap[0][rank2]==1 && it!=Kicker.end()){
        	        (*it)=rank2; it++; 
                }
            }
            return 1;
        }
    }
    return 0;
}

void _high_cards(const int handmap[][15], std::vector<int> &Kicker){
	auto it=Kicker.begin();
    it++;
    for(int rank=14; rank>=2; rank--){
    	if(handmap[0][rank]==1 && it!=Kicker.end()) {  (*it)=rank;it++; }
    }
}
