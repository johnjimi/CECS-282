#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cstring>
class date
{
     public:
            int daysBetween(Date D);
            int getMonth();
            int getDay();
            int getYear();
            int getYearOffset();      
            
            int getJulian();
          
     private: 
              int month;
              int day;
              int year;
              void setJulian(int julianDate);
              int convertingGregorianToJulian(int M, int D, int Y);
     
     public:
            Date();
            Date(int julianDate);
            Date(int M, int D, int Y);
    public:        
            void display() const;
            void incrDate(int N);
            void decrDate(int N); 
};
