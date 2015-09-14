#include "date.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


 Date:: Date()
    {
             month = 5;
             day = 11;
             year = 1959;
    } // end myDate()
Date::Date(int M, int D, int Y)
{
    if ( ( M < 1 || M > 12 ) || ( D < 1 || D > 31 ) || ( Y < 1 ) )
    {
        month = 5;
        day = 11;
        year = 1959;
    } 
    else
    {
        month = M;
        day = D;
        year = Y;
    }
}// end myDate(int M, int D, int Y)
    
   void Date:: display() const
   {
        char monthAbbreviated[3];
        switch(month)
        {
             case 1: strcpy(monthAbbreviated, "Jan");
                  break;
             case 2: strcpy(monthAbbreviated, "Feb");
                  break;
             case 3: strcpy(monthAbbreviated, "Mar");
                  break;
             case 4: strcpy(monthAbbreviated, "Apr");
                  break;
             case 5: strcpy(monthAbbreviated, "May");
                  break;
             case 6: strcpy(monthAbbreviated, "Jun");
                  break;
             case 7: strcpy(monthAbbreviated, "Jul");
                  break;
             case 8: strcpy(monthAbbreviated, "Aug");
                  break;
             case 9: strcpy(monthAbbreviated, "Sep");
                  break;
             case 10:strcpy(monthAbbreviated, "Oct");
                  break;
             case 11:strcpy(monthAbbreviated, "Nov");
                  break;
             case 12:strcpy(monthAbbreviated, "Dec");
                  break;
        }// end switch statement
                                                      
        cout << monthAbbreviated << " " << day << ", " << year; 
   } // end display() consts

    void Date:: incrDate(int N)
    {
         int m = month;
         int d = day;
         int y = year;

        //converting the gregorian to julian
         int julianDate = this->convertingGregorianToJulian(m, d, y);
       
          julianDate = julianDate + N; 

        //converting back to gregorian
        this->setJulian(julianDate);
    } // end incrDate(int N) method     
  void Date:: decrDate(int N)
    {
         int m = month;
         int d = day;
         int y = year;

         int julianDate = this->convertingGregorianToJulian(m, d, y);

         julianDate = julianDate - N;
         this->setJulian(julianDate);      
    
    } // end decrDate(int N) method     

    int Date:: daysBetween(Date D)
    {
        //date
        int y = this->year;
        int m = this->month;
        int d = this->day;
        int julianDate_this = this->convertingGregorianToJulian(m, d, y);

        y = D.getYear();
        m = D.getMonth();
        d = D.getDay();

        int julianDate_d = this->convertingGregorianToJulian(m, d, y);
     return julianDate_d - julianDate_this;        
    } // end daysBetween(Date D) method

    int Date::convertingGregorianToJulian(int M, int D, int Y)
	  {
        int y = Y;
        int m = M;
        int d = D;

/**         
         // The algorithms below are provided on the website: 
         //http://aa.usno.navy.mil/faq/docs/JD_Formula.php
         // Converting from Gregorian to Julian         
         // JD = K-32075 + 1461 * (I + 4800 + ( J - 14 ) / 12) / 4 + 367 * (J - 2 - ( J -14 )/ 12 * 12)
        // /12 - 3* ((I+4900+(J-14)/12)/100) / 4 
**/ 

        //converting gregorian to julian
        int julianDate = ( 1461 * ( Y + 4800 + ( M - 14 ) / 12 ) ) / 4
		       + ( 367 * ( M - 2 - 12 * ( ( M - 14 ) / 12 ) ) ) / 12
			   - ( 3 * ( ( Y + 4900 + ( M - 14 ) / 12 ) / 100 ) ) / 4
			   + D - 32075;
        return julianDate;
    }
 
    int Date:: getMonth()
    {
        return month;
    }// end getMonth() method 

   int Date:: getDay()
    {
        return day;
    } // end getDay() method

    int Date:: getYear()
    {
        return year;
    }// end getYear method       

    int Date:: getYearOffset()
    {
        int m = month;
        int d = day;
        int y = year;
        
        //converting gregorian to julian complete
        int julianDate = this->convertingGregorianToJulian(m, d, y);

        //set a date to the first of the year.
        m = 1;
        d = 1;

        //First of the year
        int julianDate_y = this->convertingGregorianToJulian(m, d, y);
 
       return julianDate - julianDate_y;           
                
    }// end getYearOffset() method
    
    void Date::setJulian(int julianDate)
	{
     /**      
     Converting from Julian --> Julian
    INTEGER JD,YEAR,MONTH,DAY,I,J,K

    L= JD+68569
    N= 4*L/146097
    L= L-(146097*N+3)/4
    I= 4000*(L+1)/1461001
    L= L-1461*I/4+31
    J= 80*L/2447
    K= L-2447*J/80
    L= J/11
    J= J+2-12*L
    I= 100*(N-49)+I+L

    YEAR= I
    MONTH= J
    DAY= K
**/ 
        int I, J, L, N, K, M, D, Y;
        L = julianDate + 68569;
        N = ( 4 * L ) / 146097;
        L = L - ( 146097 * N + 3 ) / 4;
        I = ( 4000 * ( L + 1 ) ) / 1461001;
        L = L - ( 1461 * I ) / 4 + 31;
        J = ( 80 * L ) / 2447;
        D = L - ( 2447 * J ) / 80;
        L = J / 11;
        M = J + 2 - ( 12 * L );
        Y = 100 * ( N - 49 ) + I + L;

        year  = Y;
        month = M;
        day   = D;
    }  
    int Date::getJulian()
    {
        int y = year;
        int d = day;
        int m = month;
        
        int julianDate = this->convertingGregorianToJulian(m, d, y);
        return julianDate;
    }    
//****************************************************//
//This method sets the date to the given julian date.//
//***************************************************//
Date::Date(int julianDate)
{
 this->setJulian(julianDate);
}
/**    
    int main()
    {
        myDate d5(8, 21, 2007);
        int x = d5.getYearOffset();
        d5.decrDate(x);
        d5.display();
        int c;
        cin >> c;
        return 0;    
    }                              
**/
