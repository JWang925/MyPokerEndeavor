std::ostream& operator<<(std::ostream& outstream, Result R){
    if(R==Result::Win) outstream << "Win" << std::endl;
    if(R==Result::Loss) outstream << "Loss" <<std::endl;
    if(R==Result::Tie) outstream << "Tie" <<std::endl;
}









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




