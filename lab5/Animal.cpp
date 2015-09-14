#include "stdafx.h"
#include "Animal.h"

int main()
{
	Animal *LA_ZooCages[10];
	for (int i = 0; i < 10; i++)
		LA_ZooCages[i] = NULL;
	bool done = false;
	int choice;
	// Zoo myZoo;//call classes
	while (!done)
	{
		cout << "Welcome to Bubbletown's Happy Zoo, Please select choices to [1]-[5]" << endl;
		cout << "[1] ADD" << endl;
		cout << "[2] REMOVE" << endl;
		cout << "[3] DISPLAY ALL ANIMALS" << endl;
		cout << "[4] DISPLAY ANIMAL COUNT" << endl;
		cout << "[5] EXIT" << endl;
		cin >> choice;

		switch (choice)
		{
			int zooCages;
			int option;
		case 1:
			//myZoo.addAnimal();
			cout << "Choose a cage, which one?" << endl;
			cin >> zooCages;
			if (LA_ZooCages[zooCages - 1] == NULL)
			{
				cout << "Which animal do you like, choose a animal!" << endl;
				cout << "1) Lizard" << endl;
				cout << "2) Snake" << endl;
				cout << "3) Eagle" << endl;
				cout << "4) Chicken" << endl;
				cout << "5) Bear" << endl;
				cout << "6) Fox" << endl;
				cout << "7) Lion" << endl;
				cout << "8) Scorpion" << endl;
				cout << "9) Alligator" << endl;
				cout << "10) Komodo Dragon (Nice)" << endl;
				cin >> option;
				switch (option)
				{
				case 1:
				{
					Animal *aptr = new Lizard;
					LA_ZooCages[zooCages - 1] = aptr;
				}//end case 1
				break;
				case 2:
				{
					Animal *aptr = new Snake;
					LA_ZooCages[zooCages - 1] = aptr;
				}//end case
				break;
				case 3:
				{
					Animal *aptr = new Eagle;
					LA_ZooCages[zooCages - 1] = aptr;
				}//end case
				break;
				case 4:
				{
					Animal *aptr = new Chicken;
					LA_ZooCages[zooCages - 1] = aptr;
				}//end case 4
				break;
				case 5:
				{
					Animal *aptr = new Bear;
					LA_ZooCages[zooCages - 1] = aptr;
				}//end case
				break;
				case 6:
				{
					Animal *aptr = new Fox;
					LA_ZooCages[zooCages - 1] = aptr;
				}//end case 6
				break;
				case 7:
				{
					Animal *aptr = new Lion;
					LA_ZooCages[zooCages - 1] = aptr;
				}//end case 7
				break;
				case 8:
				{
					Animal *aptr = new Scorpion;
					LA_ZooCages[zooCages - 1] = aptr;
				}//end case
				break;
				case 9:
				{
					Animal *aptr = new Alligator;
					LA_ZooCages[zooCages - 1] = aptr;
				}//end case
				break;
				case 10:
				{
					Animal *aptr = new KomodoDragon;
					LA_ZooCages[zooCages - 1] = aptr;
				}//end case
				break;

				default:
					cout << "Please choose ones in the liste";
				}//end default 
			}//end case choices
			else
				cout << "Sorry, but this cage is already";
			cout << " OCCUPIED." << endl;
			break;
		case 2:
			cout << "Which cage?" << endl;
			cin >> zooCages;
			if (zooCages > 10)
				cout << "ERROR! THIS CAGE DOES NOT EXIST!"
				<< endl;
			else if (LA_ZooCages[zooCages - 1] == 0)
			{
				cout << "Teh Zookeeper says that this cage is ";
				cout << "already EMPTY" << endl;
			}//end else if
			else
			{
				LA_ZooCages[zooCages - 1]-> ~Animal();
				LA_ZooCages[zooCages - 1] = NULL;
			}//end else
			break;
			//end choice 2
		case 3:
			cout << "Zoo Cages" << endl;
			for (int i = 0; i < 10; i++)
			{
				if (LA_ZooCages[i] == NULL)
					cout << i + 1 << " [empty]" << endl;
				else
					cout << i + 1 << " [" << LA_ZooCages[i] ->
					getAnimalType() << "] " << *(LA_ZooCages[i])
					<< endl;
			}//end for loop
			break;
		case 4:
			cout << Animal::getCounterValue() << " ANIMAL(S)";
			cout << " IN THE ZOO!" << endl;
			break;
		case 5:
			done = true;
			break;
		default:
			cout << "Please make a selection";
			cout << "from the menu below!:" << endl;
		}//end default
	}// end case
	return 0;
}// end main
