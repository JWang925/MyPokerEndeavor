
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
void test6();

int main(){
	std::srand(std::time(0));
	test4();
	test5();
	test6();
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
	hand1.print();
	PokerHand hand2("KS AS TS QS JD 9S 8S");
	std::cout << "Hand: \"KS AS TS QS JD 9S 8S\"" <<std::endl;
	hand2.print();	
}

void test6(){ //poker hand type evaluation benchmark
	cout << "*****Test6: Hand Frequency calculator and benchmark*****" <<endl;
	long ihand=0; 
	long nhand=10000000;
	vector<long> count{0,0,0,0,0,0,0,0,0};

	vector<int> dummy(6);

	clock_t begin= clock();
	while(ihand<nhand){
		PokerHand hand(7);
		if( hand._is_SF(dummy)) { count[0]++; ihand++; continue;}
		if( hand._is_quad(dummy)) {count[1]++; ihand++; continue;}
		if( hand._is_FH(dummy)) {count[2]++;  ihand++;continue;}
		if( hand._is_flush(dummy)) {count[3]++;  ihand++;continue;}
		if( hand._is_straight(dummy)) {count[4]++; ihand++; continue;}
		if( hand._is_three_of_a_kind(dummy)){ count[5]++; ihand++; continue;}
		if( hand._is_two_pairs(dummy)){ count[6]++;ihand++;  continue;}
		if( hand._is_one_pair(dummy)) {count[7]++;ihand++; continue;} 
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
