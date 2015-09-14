#include <iostream>
#include <cstring>
//some packages missing (;


using namespace std;

class Date{
        public:
                Date();
                Date(int M, int D, int Y);
                void display() const;
                void incrDate(int N);
                void decrDate(int N);
                int daysBetween(Date D);
                int getMonth();
                int getDay();
                int getYear();
                int getYearOffset();
                
        private:
                int month;
                int day;
                int year;
};//end

Date::Date(){
        month = 5;
        day = 11;
        year = 1955;
}

Date::Date(int M, int D, int Y){
        if ( ( M < 1 || M > 12 ) || ( D < 1 || D > 31 ) || ( Y < 1 ) ){
             month = 5;
             day = 11;
             year = 1955;
       } else {
             month = M;
             day = D;
             year = Y;
       }
}

void Date::display() const{
     char months[3];
     switch(month){
            case 1: strcpy(months, "Jan"); break;
            case 2: strcpy(months, "Feb"); break;
            case 3: strcpy(months, "Mar"); break;
            case 4: strcpy(months, "Apr"); break;
            case 5: strcpy(months, "May"); break;
            case 6: strcpy(months, "Jun"); break;
            case 7: strcpy(months, "Jul"); break;
            case 8: strcpy(months, "Aug"); break;
            case 9: strcpy(months, "Sep"); break;
            case 10: strcpy(months, "Oct"); break;
            case 11: strcpy(months, "Nov"); break;
            case 12: strcpy(months, "Dec"); break;  
     }
     cout << months << " " << day << ", " << year;   
}     

void Date::incrDate(int N){
     int y = year;
     int m = month;
     int d = day;
     
     //convert the gregorian to julian
     int jd = ( 1461 * ( y + 4800 + ( m - 14 ) / 12 ) ) / 4 +
          ( 367 * ( m - 2 - 12 * ( ( m - 14 ) / 12 ) ) ) / 12 -
          ( 3 * ( ( y + 4900 + ( m - 14 ) / 12 ) / 100 ) ) / 4 +
          d - 32075;
          
     jd = jd + N; //Add the days to the julian date
     
     //convert back to gregorian
     int i, j, l, n, k;
     l = jd + 68569;
     n = ( 4 * l ) / 146097;
     l = l - ( 146097 * n + 3 ) / 4;
     i = ( 4000 * ( l + 1 ) ) / 1461001;
     l = l - ( 1461 * i ) / 4 + 31;
     j = ( 80 * l ) / 2447;
     d = l - ( 2447 * j ) / 80;
     l = j / 11;
     m = j + 2 - ( 12 * l );
     y = 100 * ( n - 49 ) + i + l;
     
     year = y;
     month = m;
     day = d;      
}

void Date::decrDate(int N){
     int y = year;
     int m = month;
     int d = day;
     
     //convert the gregorian to julian
     int jd = ( 1461 * ( y + 4800 + ( m - 14 ) / 12 ) ) / 4 +
          ( 367 * ( m - 2 - 12 * ( ( m - 14 ) / 12 ) ) ) / 12 -
          ( 3 * ( ( y + 4900 + ( m - 14 ) / 12 ) / 100 ) ) / 4 +
          d - 32075;
          
     jd = jd - N; //Add the days to the julian date
     
     //convert back to gregorian
     int i, j, l, n, k;
     l = jd + 68569;
     n = ( 4 * l ) / 146097;
     l = l - ( 146097 * n + 3 ) / 4;
     i = ( 4000 * ( l + 1 ) ) / 1461001;
     l = l - ( 1461 * i ) / 4 + 31;
     j = ( 80 * l ) / 2447;
     d = l - ( 2447 * j ) / 80;
     l = j / 11;
     m = j + 2 - ( 12 * l );
     y = 100 * ( n - 49 ) + i + l;
     
     year = y;
     month = m;
     day = d;      
}

int Date::daysBetween(Date D){
    //this date 
     int y = this->year;
     int m = this->month;
     int d = this->day;
     
     //convert the gregorian to julian
     int jd_this = ( 1461 * ( y + 4800 + ( m - 14 ) / 12 ) ) / 4 +
          ( 367 * ( m - 2 - 12 * ( ( m - 14 ) / 12 ) ) ) / 12 -
          ( 3 * ( ( y + 4900 + ( m - 14 ) / 12 ) / 100 ) ) / 4 +
          d - 32075;
     
     y = D.getYear();
     m = D.getMonth();
     d = D.getDay();
     
     int jd_d = ( 1461 * ( y + 4800 + ( m - 14 ) / 12 ) ) / 4 +
          ( 367 * ( m - 2 - 12 * ( ( m - 14 ) / 12 ) ) ) / 12 -
          ( 3 * ( ( y + 4900 + ( m - 14 ) / 12 ) / 100 ) ) / 4 +
          d - 32075;
          
     return jd_d - jd_this;
}

int Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}

int Date::getDay(){
    return day;
}

int Date::getYearOffset(){
     int y = year;
     int m = month;
     int d = day;
     
     //convert the gregorian to julian complete
     int jd = ( 1461 * ( y + 4800 + ( m - 14 ) / 12 ) ) / 4 +
          ( 367 * ( m - 2 - 12 * ( ( m - 14 ) / 12 ) ) ) / 12 -
          ( 3 * ( ( y + 4900 + ( m - 14 ) / 12 ) / 100 ) ) / 4 +
          d - 32075;
     
     //set a date to the first of the year.
     m = 1;
     d = 1;  
     
     //First of the year
     int jd_y = ( 1461 * ( y + 4800 + ( m - 14 ) / 12 ) ) / 4 +
          ( 367 * ( m - 2 - 12 * ( ( m - 14 ) / 12 ) ) ) / 12 -
          ( 3 * ( ( y + 4900 + ( m - 14 ) / 12 ) / 100 ) ) / 4 +
          d - 32075;
          
     return jd - jd_y;
}

int main() {
        Date d5(8, 21, 2007);
    //---------------------
    //--------------------
    //------------------
        return 0;
}
