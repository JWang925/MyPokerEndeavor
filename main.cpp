
#include<iostream>
#include<string>
#include"pokerhand.h"
#include<ctime>
#include<cstdlib>
#include"card.h"
#include"deck.h"

using namespace std;

void test4();
void test5();
void test6(); //PokerHand::_is_SF/_is_Quad/etc test and compare to statistical results
void test7(); //PokerHand::GetStrength 
void test8();
void test9();
void test10();
void test11();

int main(){
	std::srand(std::time(0));
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	test11();
	return 0;
}


void test4(){ //test of deck generation, shuffle and deal.
	cout << "*****Test4: Deck generation and shuffling*****" <<endl;
	Deck deck;
	std::cout << "deck before shuffling:" << std::endl; 
	deck.print();
	deck.shuffle();
	std::cout << "deck after shuffling:" << std::endl;
	deck.print();
	std::cout << "dealing a card:" << std::endl;
	std::cout << "Card being dealt is: " << deck.deal() << std::endl;
	deck.print();
}

void test5(){ //generate and print PokerHand
	cout << "*****Test5: PokerHand generation and display*****" <<endl;
	PokerHand hand1("2H 3H 4H 5H 6D 7H 8H");
	std::cout << "Hand: \"2H 3H 4H 5H 6D 7H 8H\"" <<std::endl;
	hand1.printarray();
	PokerHand hand2("KS AS TS QS JD 9S 8S");
	std::cout << "Hand: \"KS AS TS QS JD 9S 8S\"" <<std::endl;
	hand2.printarray();	
}

void test6(){ //poker hand type evaluation benchmark
	cout << "*****Test6: Hand Frequency calculator and benchmark*****" <<endl;
	long ihand=0; 
	long nhand=10000000;
	vector<long> count{0,0,0,0,0,0,0,0,0};

	clock_t begin= clock();
	while(ihand<nhand){
		PokerHand hand(7);
		if( hand._is_SF()) { count[0]++; ihand++; continue;}
		if( hand._is_quad()) {count[1]++; ihand++; continue;}
		if( hand._is_FH()) {count[2]++;  ihand++;continue;}
		if( hand._is_flush()) {count[3]++;  ihand++;continue;}
		if( hand._is_straight()) {count[4]++; ihand++; continue;}
		if( hand._is_three_of_a_kind()){ count[5]++; ihand++; continue;}
		if( hand._is_two_pairs()){ count[6]++;ihand++;  continue;}
		if( hand._is_one_pair()) {count[7]++;ihand++; continue;} 
		count[8]++;ihand++; //the hands reaching this point are high-card
		
	}
	clock_t end = clock();
	double elapsed_secs= double(end-begin) / CLOCKS_PER_SEC;
	cout << nhand << " hand evaluation done in " << elapsed_secs << " seconds" << endl;
	cout << "Frequency table:" <<std::endl;
	cout << "SF (Expected: 0.0311%):      " << (double)count[0]/nhand << endl; 
	cout << "quad (Expected: 0.168%):     " << (double)count[1]/nhand << endl; 
	cout << "FH (Expected: 2.60%):        " << (double)count[2]/nhand << endl; 
	cout << "flush (Expected: 3.03%):     " << (double)count[3]/nhand << endl; 
	cout << "straight (Expected: 4.62%):  " << (double)count[4]/nhand << endl; 
	cout << "trip (Expected: 4.83%):      " << (double)count[5]/nhand << endl; 
	cout << "two-pair (Expected: 23.5%):  " << (double)count[6]/nhand << endl; 
	cout << "pair (Expected: 43.8%):      " << (double)count[7]/nhand << endl; 
	cout << "high-card(Expected: 17.4%):  " << (double)count[8]/nhand << endl; 
}



void test7(){
	cout << "*****Test7: Hand Strength Evaludate Function and return*****" <<endl;
	PokerHand hand(7);
	std::cout << "Hand map is:" << std::endl;
	hand.printarray();
	std::cout << "Hand is:" <<std::endl;
	hand.print();
	vector <int> strength=hand.GetStrength();
	std::cout << "Hand strength is:";
	for (auto& i : strength) std::cout << i << ' ';
	std::cout << std::endl;
}


void test8(){
	cout << "*****Test8: Use the hand strength function for 10M hands*****" <<endl;	
	long ihand=0; 
	long nhand=10000000;
	vector<long> count{0,0,0,0,0,0,0,0,0};

	clock_t begin= clock();
	while(ihand<nhand){
		PokerHand hand(7);
		vector <int> strength=hand.GetStrength();
		count[strength[0]]++; 
		ihand++;
	}
	clock_t end = clock();


	std::reverse(count.begin(),count.end());
	double elapsed_secs= double(end-begin) / CLOCKS_PER_SEC;
	cout << nhand << " hand evaluation done in " << elapsed_secs << " seconds" << endl;
	cout << "Frequency table:" <<std::endl;
	cout << "SF (Expected: 0.0311%):      " << (double)count[0]/nhand << endl; 
	cout << "quad (Expected: 0.168%):     " << (double)count[1]/nhand << endl; 
	cout << "FH (Expected: 2.60%):        " << (double)count[2]/nhand << endl; 
	cout << "flush (Expected: 3.03%):     " << (double)count[3]/nhand << endl; 
	cout << "straight (Expected: 4.62%):  " << (double)count[4]/nhand << endl; 
	cout << "trip (Expected: 4.83%):      " << (double)count[5]/nhand << endl; 
	cout << "two-pair (Expected: 23.5%):  " << (double)count[6]/nhand << endl; 
	cout << "pair (Expected: 43.8%):      " << (double)count[7]/nhand << endl; 
	cout << "high-card(Expected: 17.4%):  " << (double)count[8]/nhand << endl; 
}



void test9(){
	cout << "*****Test9: Initialize a deck, deal then evaluate for 10M hands*****" <<endl;	
	long ihand=0; 
	long nhand=10000000;
	vector<long> count{0,0,0,0,0,0,0,0,0};

	clock_t begin= clock();
	while(ihand<nhand){
		Deck theDeck;
		PokerHand theHand;
		theDeck.shuffle();
		for (int i=0; i<7;i++) theHand.add(theDeck.deal());
		vector <int> strength=theHand.GetStrength();
		count[strength[0]]++; 
		ihand++;
	}
	clock_t end = clock();


	std::reverse(count.begin(),count.end());
	double elapsed_secs= double(end-begin) / CLOCKS_PER_SEC;
	cout << nhand << " hand evaluation done in " << elapsed_secs << " seconds" << endl;
	cout << "Frequency table:" <<std::endl;
	cout << "SF (Expected: 0.0311%):      " << (double)count[0]/nhand << endl; 
	cout << "quad (Expected: 0.168%):     " << (double)count[1]/nhand << endl; 
	cout << "FH (Expected: 2.60%):        " << (double)count[2]/nhand << endl; 
	cout << "flush (Expected: 3.03%):     " << (double)count[3]/nhand << endl; 
	cout << "straight (Expected: 4.62%):  " << (double)count[4]/nhand << endl; 
	cout << "trip (Expected: 4.83%):      " << (double)count[5]/nhand << endl; 
	cout << "two-pair (Expected: 23.5%):  " << (double)count[6]/nhand << endl; 
	cout << "pair (Expected: 43.8%):      " << (double)count[7]/nhand << endl; 
	cout << "high-card(Expected: 17.4%):  " << (double)count[8]/nhand << endl; 
}

void test10(){
	cout << "*****Test10: Initialize a deck, deal 5 players then evaluate for 10M hands*****" <<endl;	
	long ihand=0; 
	long nhand=10000000;
	vector<long> count{0,0,0,0,0,0,0,0,0};

	clock_t begin= clock();
	while(ihand<nhand){
		Deck theDeck;
		PokerHand theHand;
		theDeck.shuffle();
		
		for(int j=0;j<5;j++){
			for (int i=0; i<7;i++) theHand.add(theDeck.deal());
			vector <int> strength=theHand.GetStrength();
			count[strength[0]]++; 
			ihand++;
		}
	}
	clock_t end = clock();


	std::reverse(count.begin(),count.end());
	double elapsed_secs= double(end-begin) / CLOCKS_PER_SEC;
	cout << nhand << " hand evaluation done in " << elapsed_secs << " seconds" << endl;
}


void test11(){
	cout << "*****Test11: Evaluate BBJ frequency, 10M hands*****" <<endl;	
	long igame=0; 
	long ngame=10000000;

	int BBJcount=0;

	clock_t begin= clock();
	while(igame<ngame){
		Deck theDeck;
		theDeck.shuffle();
		igame++;
		if(igame%100000==0) { cout<<"*" << std::flush;};



		std::vector <PokerHand> Hands;
		Hands.resize(9);

		theDeck.shuffle();
		vector <Card> Board;
		Board.reserve(5); //reserve space for acceleration
		for(int i=0;i<5;i++) { //deal the board first
			Card temp = theDeck.deal();
			temp.SetType(2);  //tag the cards to type Board
			Board.push_back(temp);
		}

		for(int i=0;i<9;i++){ //deal to the 9 players
			for (int j=0; j<2;j++){ //2 cards per player
				Card temp=theDeck.deal();
				temp.SetType(1); //tag the cards to type Private
				Hands[i].add(temp);
			}
			for (auto& card:Board) Hands[i].add(card); //add the boards position 2,3,4,5,6
		}


		//now iterate through the hands and count the numbers of SF and Quad T or better.	
		vector <int> BBJplayer;
		for(int i=0;i<9;i++){
			if( Hands[i]._is_SF()) { BBJplayer.push_back(i); continue;}
			if( Hands[i]._is_quad()) {
				if( Hands[i].GetStrength().at(1) >= 10) {BBJplayer.push_back(i); continue;}
			}
		}

		if( BBJplayer.size()<2) continue; //BBJ couldn't exists
		
		if( Hands[BBJplayer[0]].ifWinnerHandContainsHoleCards()==1 && Hands[BBJplayer[1]].ifWinnerHandContainsHoleCards()==1) 
			BBJcount++; 
	}
	clock_t end = clock();

	double elapsed_secs= double(end-begin) / CLOCKS_PER_SEC;
	cout << ngame << " 9-handed game evaluation done in " << elapsed_secs << " seconds" << endl;
	cout << "BBJ frequency: " << BBJcount <<std::endl;
}

/*
void test2(){
	clock_t begin= clock();

	long ihand=0;
	long nhand=1000000;
	while(ihand<nhand){
		PokerHand h1(7);
		PokerHand h2(7);
		Result out=compare(h1,h2);
		ihand++;
	}

	clock_t end = clock();
	double elapsed_secs= double(end-begin) / CLOCKS_PER_SEC;
	cout << nhand << " hand comparisons done in " << elapsed_secs << " seconds" << endl;
}
*/


/*



	PokerHand hand3("3H 2D 4H 5H 7H 6H 4D");
	PokerHand hand4("KS AS TS QS JS 2D 2S");
	
	cout<<out;

	PokerHand hand5("2H 2D 4H 3H 3S 3D 8H");
	PokerHand hand6("AD AS TS AC JD AH 8S");
	
	cout<<out;


*/
