#include "myDate.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib> 
#include <ctime> 
    
using namespace std;

 myDate:: myDate()
    {
             month = 5;
             day = 11;
             year = 1959;
    } // end myDate()
    
    
      myDate::myDate(int M, int D, int Y)
	{
        if ( ( D < 1 || D > 31 ) || ( M < 1 || M > 12 ) ||  ( Y < 1 ) )
		{
                 month = 5;
                 day   = 11;
                 year  = 1959;
        }
		else
		{
                 month = M;
                 day   = D;
                 year  = Y;
        }
    }// end myDate(int M, int D, int Y)
    
    
    void myDate:: display() const
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
   }
   
   
   void myDate:: incrDate(int N)
    {
         int m = month;
         int d = day;
         int y = year;
         int julianDate = this->convertingGregorianToJulian(m, d, y);
          julianDate = julianDate + N; 
        this->setJulian(julianDate);
    } 
    
    void myDate:: decrDate(int N)
    {
         int m = month;
         int d = day;
         int y = year;
         int julianDate = this->convertingGregorianToJulian(m, d, y);
         julianDate = julianDate - N;
         this->setJulian(julianDate);      
    } // end decrDate(int N) method     
     
     int myDate:: daysBetween(myDate D)
    {
        int y = this->year;
        int m = this->month;
        int d = this->day;
        int julianDate_this = this->convertingGregorianToJulian(m, d, y);
        y = D.getYear();
        m = D.getMonth();
        d = D.getDay();

        int julianDate_d = this->convertingGregorianToJulian(m, d, y);

          
     return julianDate_d - julianDate_this;        
    } 
    int myDate::convertingGregorianToJulian(int M, int D, int Y)
	{
	    int y = Y;
      int m = M;
      int d = D;

       int julianDate = ( 1461 * ( Y + 4800 + ( M - 14 ) / 12 ) ) / 4
		       + ( 367 * ( M - 2 - 12 * ( ( M - 14 ) / 12 ) ) ) / 12
			   - ( 3 * ( ( Y + 4900 + ( M - 14 ) / 12 ) / 100 ) ) / 4
			   + D - 32075;
        return julianDate;
    }
    int myDate:: getMonth()
    {
        return month;
    }// end getMonth() method 

   int myDate:: getDay()
    {
        return day;
    } // end getDay() method

  int myDate:: getYear()
    {
        return year;
    }// end getYear method       
 int myDate:: getYearOffset()
    {
        int m = month;
        int d = day;
        int y = year;
        
        int julianDate = this->convertingGregorianToJulian(m, d, y);

        m = 1;
        d = 1;
        int julianDate_y = this->convertingGregorianToJulian(m, d, y);
 
       return julianDate - julianDate_y;           
                
    }
    
    void myDate::setJulian(int julianDate)
	{

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

    
    
    
