

#include "stdafx.h"
#include <iostream>
#include <cstdlib> // defines general purpose functions such as random numbers generation
#include <ctime> // contains definitions of functions to get and manipulate date and time information
#include <iomanip> // allows me to use the setw() function
#include <vector>
#include <numeric> //allows to use the accumulate function for req. # 3
#include <algorithm> //defines a collection of functions especially designed to be used on ranges of elements.
#include <set>

using namespace std;

//main function, or main method to execute
int main()
{
	int i, j;
	int randNum;
	int avg;
	int counter;

	// Define a vector object
	vector<int> vect;
	/*
	Write a program that generates 10,000 random integers between 1 and 100 and
	store them in an STL container.
	*/


	//srand(time(0));

	for (int i = 0; i <= 9999; i++)
	{
		randNum = rand() % 100 + 1;
		{
			vect.push_back(randNum);// Accepts as an argument a value to be
			// inserted into the vector after the last element.      
		}//end ran num
	}//end for

	/*
	**********************NOT REQUIRED************************************
	This generates the numbers in no order in the STL container

	// Displays 10000 iterations NOT sorted
	for(counter = 0; counter < vect.size(); counter++)
	cout << setw(4)<<vect[counter] <<setw(4);
	cout << endl;
	cout << "Press Enter to sort the integers in the STL containter";
	cout << " in ascending order" << endl;
	cout << endl;
	cin.ignore();
	*/
	//********************IN LAB 6*****************************************

	// This sorts the number from the smallest to the largest.    
	sort(vect.begin(), vect.end());
	vector<int>::iterator iter = vect.begin();


	//try the copy fuction alg
	while (iter != vect.end())
	{
		cout << setw(4) << *iter << setw(4);
		iter++;
	}//end while
	cout << endl;
	cout << endl;
	// Print the sum of all the numbers
	int sum = accumulate(vect.begin(), vect.end(), 0);
	cout << "Sum of outputs in STL container: \n" << sum << endl;
	cout << endl;
	cout << "Expected size of STL container:" << endl << "10000\n" << endl;
	cout << "Size of STL container:\n" << vect.size() << endl;
	cout << endl;

	// Pause the output at this point and ask the user to press any key to continue.
	cout << "Press Enter to calculate the average of the STL container\n";
	cin.ignore();   // Pauses the program to have the user type something
	// Print out the average of all integers in the STL containter.    
	if (vect.size() > 0)
	{
		avg = sum / vect.size();
	}//end if

	cout << "Average of outputs in STL :" << avg << endl;
	cin.ignore();

	/* Print the numbers 1 through 100 followed by a colon followed, followed by
	the number of times that number appears in the STL container.
	*/
	cout << "Press enter to display the numbers between 1 and 100\n";
	cout << "followed by a colon and display the number of times\n";
	cout << "that the number apppeared in the STL container:\n";
	cout << endl;
	cin.ignore();
	for (iter = vect.begin(); iter < vect.end(); iter++)
	{
		//myMap[*iter]++;
		for (i = 0; i < 101; i++)

		{
			cout << setw(5) << i << ":" << count(vect.begin(),
				vect.end(), i) << ",\t ";
		}//end for
		cin.ignore();
		return 0;
	}//end for
} // end class STL container

