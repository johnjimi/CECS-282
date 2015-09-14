#include "stdafx.h"
#include "upDate.h"
#include <string>
#include <iostream>
using namespace std;

int upDate::counter = 0;

// This is the default constructor.                                   
upDate::upDate()
{
	calendarDate = new int[3];
	calendarDate[0] = 5; // This is the month
	calendarDate[1] = 11;// This is the day
	calendarDate[2] = 1959; // This is the year
	counter++; // increment counter
} // end myDate()

upDate::~upDate()
{
	counter--;
	delete[] calendarDate;
}



upDate::upDate(int M, int D, int Y)
{
	calendarDate = new int[3];
	if ((M < 1 || M > 12) || (D < 1 || D > 31) || (Y < 1))
	{
		calendarDate[0] = 5; // This is the month
		calendarDate[1] = 11; // This is the day
		calendarDate[2] = 1959; // This is the year
	} //end if statement

	else
	{
		calendarDate[0] = M; // This is the month
		calendarDate[1] = D; // This is the day
		calendarDate[2] = Y; // This is the year
	} // end else statement
	counter++; // increment counter
}// end upDate(int M, int D, int Y)


//Copy constructor
upDate::upDate(const upDate &myCalendarDate)
{
	// if (*this != myCalendarDate)
	//{
	calendarDate = new int[3];
	calendarDate[0] = myCalendarDate.calendarDate[0];
	calendarDate[1] = myCalendarDate.calendarDate[1];
	calendarDate[2] = myCalendarDate.calendarDate[2];
	counter++;
	//}
}//end copy constructor



//method gets the MonthName
char* upDate::getMonthName()
{
	char* nameOfMonth = new char[9];
	
	
	//switch case,
	switch (calendarDate[0])
	{
	case 1: string(nameOfMonth, "January");
		break;
	case 2:string(nameOfMonth, "Febuary");
		break;
	case 3:string(nameOfMonth, "March");
		break;
	case 4:string(nameOfMonth, "April");
		break;
	case 5:string(nameOfMonth, "May");
		break;
	case 6:string(nameOfMonth, "June");
		break;
	case 7:string(nameOfMonth, "July");
		break;
	case 8:string(nameOfMonth, "August");
		break;
	case 9:string(nameOfMonth, "September");
		break;
	case 10:string(nameOfMonth, "October");
		break;
	case 11:string(nameOfMonth, "November");
		break;
	case 12:string(nameOfMonth, "December");
		break;

	}// end switch statement
	return nameOfMonth;
}// end string* getMonthName()


//thid method coverts gregorian to Julian
int upDate::convertingGregorianToJulian(int M, int D, int Y)
{
	int y = Y;
	int m = M;
	int d = D;

	//calculations
	//gregorian to julian
	int julianDate = (1461 * (Y + 4800 + (M - 14) / 12)) / 4
		+ (367 * (M - 2 - 12 * ((M - 14) / 12))) / 12
		- (3 * ((Y + 4900 + (M - 14) / 12) / 100)) / 4
		+ D - 32075;
	return julianDate;
}//end int upDate

void upDate::setJulian(int julianDate)
{

	int I, J, L, N, K, M, D, Y;
	L = julianDate + 68569;
	N = (4 * L) / 146097;
	L = L - (146097 * N + 3) / 4;
	I = (4000 * (L + 1)) / 1461001;
	L = L - (1461 * I) / 4 + 31;
	J = (80 * L) / 2447;
	D = L - (2447 * J) / 80;
	L = J / 11;
	M = J + 2 - (12 * L);
	Y = 100 * (N - 49) + I + L;

	calendarDate[2] = Y;
	calendarDate[0] = M;
	calendarDate[1] = D;
}//end upDate::setJulian


//accessor method, juilans
int upDate::getJulian()
{
	int y = calendarDate[2];
	int d = calendarDate[1];
	int m = calendarDate[0];

	// This converts gregorian to julian
	int julianDate = this->convertingGregorianToJulian(m, d, y);
	return julianDate;
}//end accessor method getJulian


//accessor method, to get the month
int upDate::getMonth()
{
	return calendarDate[0];
}// end getMonth() method 

//accessor method
int upDate::getDay()
{
	return calendarDate[1];
} // end getDay() method

//accessor method
int upDate::getYear()
{
	return calendarDate[2];
}// end getYear method       

//end overloading
upDate upDate::operator =(const upDate &myDate)
{
	for (int i = 0; i < 3; i++)
	{
		calendarDate[i] = myDate.calendarDate[i];
	}//end for loop
	return *this;
}
//end upDate::operator
upDate upDate::operator++()
{//overloads ++
	int julianDate = this->getJulian();
	julianDate++;
	this->setJulian(julianDate);
	return *this;
}//end operator++


//method for operator <
bool upDate::operator<(upDate other)
{//overloads <
	int e = getJulian() - other.getJulian();
	if (e < 0) return true;
	else if (e >= 0)return false;

}//end bool upDate::operator

//method for upDate::operator
bool upDate::operator>(upDate other)
{//overloads >

	int e = getJulian() - other.getJulian();
	if (e < 0)
		return false;
	else if (e >= 0)
		return true;
}//end update::operator 

//method for operator ++, param x
upDate upDate::operator++(int x)
{
	upDate temp = *this;
	int julianDate = this->getJulian();
	julianDate++;
	this->setJulian(julianDate);
	return temp;
}//end update::update operator++

//method for operator -- 
upDate upDate::operator--()
{
	int julianDate = this->getJulian();
	julianDate--;
	this->setJulian(julianDate);
	return *this;
}//end update::operator --


//end update::Operator param x
upDate upDate::operator--(int x)
{
	upDate temp = *this;
	int julianDate = this->getJulian();
	julianDate--;
	this->setJulian(julianDate);
	return temp;

}//end operator --


upDate upDate::operator+=(int other)
{//overloads +=
	int l = getJulian() + other;
	setJulian(l);
	return *this;
}//end update::operator +-

//method for operator ==
bool upDate::operator==(upDate other)
{
	int l = getJulian() - other.getJulian();
	if (l == 0)
		return true;
	else if (l != 0)
		return false;
}//end update::operator


//Object,
upDate operator+(upDate d, int n)
{
	int julianDate = d.getJulian();
	d.setJulian(julianDate + n);
	return d;
}//end upDate operator+

//method sets the date, +, overloading
upDate operator+(int n, upDate d)
{
	int julianDate = d.getJulian();
	d.setJulian(julianDate + n);
	return d;
}//end operator +

//mutator method
upDate operator-(upDate d, int n)
{
	int julianDate = d.getJulian();
	d.setJulian(julianDate - n);
	return d;
}//end operator -

//method for update, accessor
int operator-(upDate d1, upDate d0)
{
	int julianDate1 = d1.getJulian();
	int julianDate0 = d0.getJulian();
	return julianDate1 - julianDate0;
}//end int operator..

//this method, overloads
ostream &operator<<(ostream& out, const upDate &d)
{
	out << d.calendarDate[0] << '/' << d.calendarDate[1] << '/' << d.calendarDate[2];
	return out;
}//end ostream & operator

//This method displays the date
void upDate::display() const
{
	cout << calendarDate[0] << " " << calendarDate[1] << " " << calendarDate[2] << endl;
}//end void upDate
