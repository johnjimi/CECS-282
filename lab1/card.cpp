#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include "Card.h"

using namespace std;

Card::Card(){
};

Card::Card(char s, int r){
	//Initiliazes the values of value and suit to the parameter values
	suit = s;
	rank = r;
};

int Card::getValue(){
	//Returns the value of the card as long as it is less than 10
	if (rank <= 10){
		return rank;
	}

	//If the value is greater than 10, we return 10 since Jacks, Queens and Kings have the same value
	else{
		return 10;
	}
}

void Card::displayCard(){
	string r, s;
	//r is rank
	//s is suit


	//We need to indentify which
	//to determine the the actual value or suit, depending how we created our CardDeck
	switch (suit){
	case 'S':
		s = "Spades";
		break;
	case 'C':
		s = "Clubs";
		break;
	case 'D':
		s = "Diamonds";
		break;
	case 'H':
		s = "Hearts";
		break;
	}

	//A switch case to indentify which string.
	switch (rank){
	case 1:
		r = "Ace";
		break;
	case 2:
		r = "Two";
		break;
	case 3:
		r = "Three";
		break;
	case 4:
		r = "Four";
		break;
	case 5:
		r = "Five";
		break;
	case 6:
		r = "Six";
		break;
	case 7:
		r = "Seven";
		break;
	case 8:
		r = "Eight";
		break;
	case 9:
		r = "Nine";
		break;
	case 10:
		r = "Ten";
		break;
	case 11:
		r = "Jack";
		break;
	case 12:
		r = "Queen";
		break;
	case 13:
		r = "King";
		break;
	}//end switch for rank, values of the card
	//Outputs the card generated from the two inputs
	cout << r << " of " << suit << endl;
}

