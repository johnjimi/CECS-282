
#include "stdafx.h"
#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>
using namespace std;

class Animal
{
public:
	//base class, pass animals, and can list data memebers
	Animal(string aniType) {
		// new animal
	}
	~Animal()// destructor for choice 2
	{
		availableCagesCounter--;
		delete typeOfAnimal;
		typeOfAnimal = 0;
	};// end deconstructor ~Animal()

	//set the specifications according to the prompt, liek if it says 
	virtual string animalSpeaks() = 0; // talk() method <--Use Talk.
	virtual string animalMovesAround() = 0; // move() method

	static int getCounterValue()
	{
		return availableCagesCounter;
	};//end static int getCounterValue

	string getAnimalType()
	{
		return *typeOfAnimal;
	};//end getAnimalType

	friend ostream &operator << (ostream &out, Animal &A)
	{
		out << A.animalSpeaks() << " " << A.animalMovesAround();
		return out;
	};//end friend

protected:
	string *typeOfAnimal;
	static int availableCagesCounter;

}; //end class Animal


/**
Creating new inheritance base classes. The base class is the general class.
**/
// Mammals class
class Mammals :public Animal
{
public:
	virtual string animalSpeaks() = 0;
	virtual string animalMovesAround() = 0;
}; // end Mammals base class,

// Birds class
class Birds : public Animal
{
public:
	virtual string animalSpeaks() = 0;
	virtual string animalMovesAround() = 0;
}; // end Bird base class

// Reptiles class
class Reptiles : public Animal
{
public:
	virtual string animalSpeaks() = 0;
	virtual string animalMovesAround() = 0;
}; // end Reptiles base class


// Arachnids class
class Arachnids : public Animal
{
public:
	virtual string animalSpeaks() = 0;
	virtual string animalMovesAround() = 0;
}; // end Arachnids base class

// Amphibians class
class Amphibians : public Animal
{
public:
	virtual string animalSpeaks() = 0;
	virtual string animalMovesAround() = 0;
}; // end Amphibians base class


/**
Creating new inheritance derived classes. The derived classes is based on, or derived from, the base class.
**/

// Lizard class
class Lizard : public Reptiles
{
public:
	Lizard() // if Lizard is added to a cage
	{
		typeOfAnimal = new string;
		*typeOfAnimal = "Lizard";
		availableCagesCounter++;
	};//end Lizard ()

	~Lizard() // if Lizard is removed from a cage
	{
		availableCagesCounter--;
		delete typeOfAnimal;
		typeOfAnimal = 0;
	};//end deconstructor Lizard

	string animalSpeaks()
	{
		return "HISS"; // ????       
	};//end string animal speaks

	string animalMovesAround()
	{
		return "(Walk)";
	};
};// end Lizard derived class      


class Snake : public Reptiles
{
public:
	Snake() // if Snake is in the cage
	{
		typeOfAnimal = new string;
		*typeOfAnimal = "Snake";
		availableCagesCounter++;
	};//end snake()

	~Snake() // if Snake is removed from the cage
	{
		availableCagesCounter--;
		delete typeOfAnimal;
		typeOfAnimal = 0;
	};//deconstructor, remove snake

	string animalSpeaks()
	{
		return "HISS";
	};//end animalspeaks

	string animalMovesAround()
	{
		return "-Slither-";
	};//end animal movinf
};// end Snake derived class 

// Eagle class
class Eagle : public Birds
{
public:
	Eagle() // if Eagle is added to a cage
	{
		typeOfAnimal = new string;
		*typeOfAnimal = "Eagle";
		availableCagesCounter++;
	};

	~Eagle() // if Eagle is removed from a cage
	{
		availableCagesCounter--;
		delete typeOfAnimal;
		typeOfAnimal = 0;
	};//end eagle

	string animalSpeaks()
	{
		return "CAWWWW";
	};//end animal speaks eagle

	string animalMovesAround()
	{
		return "Woosh";
	};//end moving

};// end Eagle derived class

class Chicken : public Birds
{
public:
	Chicken()
	{
		typeOfAnimal = new string;
		*typeOfAnimal = "Chicken";
		availableCagesCounter++;
	};//end constructor

	~Chicken()
	{
		availableCagesCounter--;
		delete typeOfAnimal;
		typeOfAnimal = 0;
	};//end deconstructor

	string animalSpeaks()
	{
		return "CLUCK";
	};//end animal speak

	string animalMovesAround()
	{
		return "Walk";
	};//end animalmove
};// end Chicken derived class   

// Bear class
class Bear :public Mammals
{
public:
	Bear()
	{
		typeOfAnimal = new string;
		*typeOfAnimal = "Bear";
		availableCagesCounter++;
	};//constructor

	~Bear()
	{
		availableCagesCounter--;
		delete typeOfAnimal;
		typeOfAnimal = 0;
	};//end deconstructor

	string animalSpeaks()
	{
		return "GROWL";
	};//end animal speaks

	string animalMovesAround()
	{
		return "Walk";
	};//end animal moves around
};// end Bear derived class      

// Lion class
class Lion : public Mammals
{
public:
	Lion() // if Lion is added to a cage
	{
		typeOfAnimal = new string;
		*typeOfAnimal = "Lion";
		availableCagesCounter++;
	};//constructor

	~Lion() // if Lion is removed from a cage
	{
		availableCagesCounter--;
		delete typeOfAnimal;
		typeOfAnimal = 0;
	};//end deconstructor

	string animalSpeaks()
	{
		return "ROAR";
	};//end animalSpeaks

	string animalMovesAround()
	{
		return "Walk";
	};//end animal moves around

};// end Lion derived class      


// Hyena class
class Fox : public Mammals
{
public:
	Fox() // if Fox is added to teh cage
	{
		typeOfAnimal = new string;
		*typeOfAnimal = "Fox";
		availableCagesCounter++;
	};//constructor

	~Fox() // if Fox is removed from a cage
	{
		availableCagesCounter--;
		delete typeOfAnimal;
		typeOfAnimal = 0;
	};//deconstructor

	string animalSpeaks()
	{
		return "-[Fox sound]-";
	};//end animalSpeaks

	string animalMovesAround()
	{
		return "Walk";
	};//end moves around
};// end Fox derived class      

// Scorpion class
class Scorpion : public Arachnids
{
public:
	Scorpion()
	{
		typeOfAnimal = new string;
		*typeOfAnimal = "Scorpion";
		availableCagesCounter++;
	};//constructor

	~Scorpion()
	{
		availableCagesCounter--;
		delete typeOfAnimal;
		typeOfAnimal = 0;
	};//end deconstructor

	string animalSpeaks()
	{
		return "HISS";
	};//end animalSpeakss

	string animalMovesAround()
	{
		return "Crawl";
	};//end animal moves around

};// end Scorpion derived class      

// Alligator class
class Alligator :public Reptiles
{
public:
	Alligator() // if Snake is added to a cage
	{
		typeOfAnimal = new string;
		*typeOfAnimal = "Alligator";
		availableCagesCounter++;
	};//constructor

	~Alligator() // if Snake is removed from a cage
	{
		availableCagesCounter--;
		delete typeOfAnimal;
		typeOfAnimal = 0;
	};//deconstructor

	string animalSpeaks()
	{
		return "HISS";
	};//end animalSpeaks

	string animalMovesAround()
	{
		return "Crawl";
	};//end move
};// end Alligator derived class      

// Komodo Dragon class
class KomodoDragon :public Reptiles
{
public:
	KomodoDragon() // if Komodo Dragon is added to a cage
	{
		typeOfAnimal = new string;
		*typeOfAnimal = "Komodo Dragon";
		availableCagesCounter++;
	};//end constructor

	~KomodoDragon() // if Komodo Dragon is removed from a cage
	{
		availableCagesCounter--;
		delete typeOfAnimal;
		typeOfAnimal = 0;
	};//end deconstructor

	string animalSpeaks()
	{
		return "HISS";
	};

	string animalMovesAround()
	{
		return "Crawl";
	};//end movement
};// end Komodo Dragon derived class 

int Animal::availableCagesCounter = 0;
//end intAnimal
#endif
