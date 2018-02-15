
#include<iostream>
#include<string>
#include"pokerhand.h"
#include<ctime>
#include<cstdlib>
#include"card.h"

using namespace std;


void test1();
void test2();
void test3();

int main(){
	test1();
	test2();
	test3();
	return 0;
}

void test3(){
	Card card(1,2);
	cout << card <<endl;

}

void test1(){
	std::srand(std::time(0));
	PokerHand hand1("2H 3H 4H 5H 6D 7H 8H");
	PokerHand hand2("KS AS TS QS JD 9S 8S");
	Result out=compare(hand1,hand2);
	cout<<out;

	PokerHand hand3("3H 2D 4H 5H 7H 6H 4D");
	PokerHand hand4("KS AS TS QS JS 2D 2S");
	out=compare(hand3,hand4);
	cout<<out;

	PokerHand hand5("2H 2D 4H 3H 3S 3D 8H");
	PokerHand hand6("AD AS TS AC JD AH 8S");
	out=compare(hand5,hand6);
	cout<<out;
}

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
