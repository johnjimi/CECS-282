#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cstring>

//package include
using namespace std;

//class, our cpp
class upDate
{
public:

	// default constructor
	upDate();

	//constructor, with some members
	upDate(int M, int D, int Y);
	//another one, copy constructor
	upDate(const upDate &calendarDate);

	//deconstructor
	~upDate();

	//accessor methods
	int getMonth();
	int getDay();
	int getYear();
	void display() const;
	
	//end setDate
	void setDate(int M, int D, int Y);

	//method for getJulian, which is Julian
	int getJulian();
	char* getMonthName();

	//counter method
	static int GetDateCount()
	{
		return counter;
	}//end getDateCounter

	//operator overloading
	upDate operator++();
	upDate operator++(int);
	upDate operator--();
	upDate operator--(int);//overloads --operator

	upDate operator=(const upDate &myDate);


	//booleans, objects
	bool operator<(upDate);
	bool operator>(upDate);
	upDate operator+=(int);
	bool operator==(upDate);

	//friend methods
	friend upDate operator+(upDate d, int n);
	friend upDate operator+(int n, upDate d);
	friend upDate operator-(upDate d, int n);
	friend int operator-(upDate d1, upDate d0);
	friend ostream &operator<<(ostream &out, const upDate &d);

	//private methods,
private:
	int *calendarDate;
	void setJulian(int julianDate);
	static int counter;
	int convertingGregorianToJulian(int M, int D, int Y);
};//end of class
