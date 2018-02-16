#include"deck.h"
#include<algorithm> // std::random_shuffle
#include<vector>

using namespace std;


Deck::Deck(){ //default initializer
	for (int i=1; i<5; i++)
		for (int j=1; j <14; j++){
			Card temp(j,i);
			thedeck.push_back(temp);
		}
}

void Deck::print(){
	for (auto &i: thedeck)
		cout << i << " ";

	std::cout << std::endl;
}



void Deck::shuffle(){
	std::random_shuffle (thedeck.begin(), thedeck.end());
}



