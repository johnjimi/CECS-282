// war-game.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include "Card.h"//Header file for Card
#include "CardDeck.h"//Header file for CardDeck

using namespace std;

int _tmain()
{
	//Member variables, we use int to calculate the cards
	int mChoice;
	int mCard1;
	int mCard2;
	int mComputerCard1;
	int mComputerCard2;
	int PlayerTotal;
	int ComputerTotal;

	char mInput = 'y';// for yes
	char mClose; //member variable that exits the program
	int mCount = 0;
	CardDeck deck;

	cout << "War Card game in C++" << endl; //introduction
	/**
	We are using a do loop to cycle through the menu
	**/
	do{
		cout << "Select an option [1]-[5]: " << endl << endl;
		cout << "[1] Get a new card deck" << endl;
		cout << "[2] Show all the cards in the deck" << endl;
		cout << "[3] Shuffle" << endl;
		cout << "[4] Play WAR!" << endl;
		cout << "[5] Exit" << endl;
		cin >> mChoice;
		cout << endl;

		//Switch case, depend what choice the user selected
		switch (mChoice){

		case 1:
			mCount = 0;
			cout << "Fetching a new deck" << endl;
			CardDeck::CardDeck();
			cout << "New Deck Created" << endl << endl;
			break;
		
		case 2:
			cout << "Remaining number of cards: " << deck.cardsLeft() << endl;
			break;

			//Calls the shuffle method in CardDeck to shuffle the deck
		case 3:
			cout << "Shuffling the deck..." << endl;
			deck.shuffle();
			cout << "The deck has been shuffled" << endl << endl;
			break;

			//Creates a new deck by calling CardDeck again to generate a new deck
		case 4:
			do{
				if (mCount < 13 ){
					//we go fetch a card to the player, which is you.
					cout << "Your card..." << endl;
					mCard1 = deck.deal();
					cout << endl;

					//we go fetch card to the computer
					cout << "Computer gets a card..." << endl;
					mComputerCard1 = deck.deal();
					cout << endl;

					cout << "You get another card..." << endl;
					mCard2 = deck.deal();
					cout << endl;

					cout << "Computer gets another card..." << endl;
					mComputerCard2 = deck.deal();
					cout << endl << endl;

					//Calcuating the cards, that the user and computer has to decide the winner
					PlayerTotal = mCard1 + mCard2;
					ComputerTotal = mComputerCard1 + mComputerCard2;


					cout << "Player: " << PlayerTotal << " points" << endl << endl;
					cout << "Computer: " << ComputerTotal << " points" << endl << endl;

					/*
					Results, comparing the values
					*/
					if (PlayerTotal > ComputerTotal){
						cout << "You win!" << endl;
					}//end if, the player has more points than the user.
					else if (ComputerTotal > ComputerTotal){
						cout << "Computer wins, You lose." << endl;
					}//end else if the computer has more points than the user
					//rare case if player and computer cards equaled
					else if (ComputerTotal == PlayerTotal){
						cout << "It is a tie." << endl;
					}//end else if

					//to 0 to 13, we need to count many times
					mCount++;
				}//end do loop, as long we are playing the game

				//Once the deck is out of cards, the user to prompted to select the option to create a new deck.
				else{
					cout << "No cards left in the Deck" << endl;
					cout << "Create a new deck to continue playing" << endl;
					break;
				}//end else, if we ran out of cards.

				//Prompt user to play again
				cout << "Wanna play again? (y/n)" << endl;
				cin >> mInput;//user can either press y or n
			}//end do loop
			while (mInput != 'n');
			break;

			//Exits the menu
		case 5:
			cout << "Exiting...thanks for playing" << endl;
			cout << endl;
			break;

			//If the user inputs a number that is greater than 5, this case will make sure that the number between 1 and 5
		default:
			do{
				cout << "Please enter a number between [1] and [5]." << endl;
				cin >> mChoice;
			} while (mChoice > 5);

			//Once the user is out of the do-while loop, they are back at the menu and have to reenter an option
			cout << "Menu" << endl;
			break;
		}

		
	} while (mChoice != 5);
	cout << "Press any key to exit." << endl;
	cin >> mClose;
	return 0;
}//end main
