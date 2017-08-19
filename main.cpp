
#include<iostream>
#include<string>
#include"abc.h"
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
/*
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
*/

long ihand=0;
while(ihand<1000000){
	PokerHand h1(7);
	PokerHand h2(7);
	Result out=compare(h1,h2);
	//cout<<out;
	ihand++;
	//cin.get();
}
	return 0;
}


