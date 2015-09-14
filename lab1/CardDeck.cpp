#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "Card.h"
#include "CardDeck.h"
#include <vector>

using namespace std;
//we are using vectors instead of arrays, we have to import it, just like java
vector<Card> deck;

CardDeck::CardDeck(){
	deck.clear();//vectoris empty
	
	Card card;//an Object called card

	char suit[] = { 'S', 'C', 'D', 'H' };

	//for loop to create 52 cards
	for (int i = 1; i < 14; i++){
		for (int j = 0; j < 4; j++){
			//push in the card in the deck, adding a card
			deck.push_back(Card(suit[j], i));
		}//end for loop
	}//end for loop
	//Call the shuffle
	shuffle();
}//end cardDeck

void CardDeck::displayCardAt(int l){
	//Displaying the card at the current index of the vector
	deck[l].displayCard();
}//end void cardDeck

int CardDeck::deal(){
	int num = deck[0].getValue();

	//Gets the card at the "top" of the deck
	deck[0].displayCard();

	/*Erases the card at the beginning of the deck, or the "top"
	Makes sure there are no repeats of cards that have been used already*/
	deck.erase(deck.begin());
	return num;
}//end int CardDeck

int CardDeck::cardsLeft(){
	//Displays all the cards using a for-loop
	for (int i = 0; i < deck.size(); i++){
		displayCardAt(i);
	}//end for loop
	//Returns the size of the vector
	return deck.size();
}//end int CardDeck

void CardDeck::shuffle(){
	//use the random
	random_shuffle(deck.begin(), deck.end());
}//end void CardDeck Shuffle method
