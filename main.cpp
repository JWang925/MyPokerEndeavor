#pragma once

#include<iostream>
#include<string>
#include"abc.h"
using namespace std;

int main(){
	PokerHand hand1("2H 3H 4H 5H 6D 7H 8H");
	PokerHand hand2("KS AS TS QS JD 9S 8S");
	Result out=compare(hand1,hand2);
	cout<<out;
	return 0;
}


