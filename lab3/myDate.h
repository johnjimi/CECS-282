class myDate
{
     public:
            int daysBetween(myDate D);
            int getMonth();
            int getDay();
            int getYear();
            int getYearOffset();      
          
     private: 
              int month;
              int day;
              int year;
              void setJulian(int julianDate);
              int convertingGregorianToJulian(int M, int D, int Y);
     
     public:
            myDate();
            myDate(int M, int D, int Y);
    public:        
            void display() const;
            void incrDate(int N);
            void decrDate(int N); 
}
