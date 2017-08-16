#include<iostream>
#include<string>
#include"abc.h"
using namespace std;

int main(){

PokerHand hand1("2H 3H 4H 5H 6H");
PokerHand hand2("KS AS TS QS JS");

Result out=compare(hand1,hand2);


return 0;
}


