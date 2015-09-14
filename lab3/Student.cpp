#include "Student.h"
#include <iostream>
#include <string>
#include <ctime> 
using namespace std;

void setStudentData(student &stud, string name, int id, int grade, Date birthday){
   Student.name = name;
   Student.identificationNumber = id;
   Student.grade = grade;
   Student.birthDay = birthday;
}

int getStudentID(student &stud){
    return Student.identificationNumber;    
}

int getStudentBirthday(student &stud){
    return Student.birthDay.getJulian();
}

void populate(student (stud[]) ){
     string names[] = {
                      "Adrian Quezada", "Gustavo Rosas", 
                      "Frodo Baggins", "Samara Hernandez", 
                      "Jairo Lopez", "Jaret Padilla", 
                      "Robert Aubert", "Rosendo Solis", 
                      "Daniel Barahona", "Kenny Lopez"};
     int seed = time(0);
    srand(seed);
   
     for (int i = 0; i < 10; i++){
        stud[i].name = names[i];
        stud[i].id = ( ( rand()%( 9999-1000 ) ) + 1000 );
                   Date date( ( ( rand()%( 2449718-2447893 ) ) + 2447893 ) );
        stud[i].birthday = date;
        stud[i].grade = ( ( rand()%( 100-50 ) ) + 50 );
     }
}

void printStudent(student &stud){
   cout << "Name: " << stud.name << " Id: " << stud.id << " Grade: " << stud.grade 
         << " Birthday: ";
   stud.birthDay.display();
   cout << endl;
}

void sortID(student **ptr){
     for (int i = 0; i < (10 - 1); i++){
         for (int j = 0; j < (10 - i); j++){
             if ( getStudentID(*ptr[j]) > getStudentID(*ptr[j + 1]) ){
                student *temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;     
             }    
         }    
     }     
}


void sortAge(student **ptr){
     int birthdays[10];
     for (int i = 0; i < 10; i++){
             birthdays[i] =  getStudentBirthday(*ptr[i]);
     }
     
     for (int i = 0; i < (10 - 1); i++){
         for (int j = 0; j < (10 - i); j++){
             if ( birthdays[j + 1] > birthdays[j] ){
                  
                int tempb = birthdays[j];
                birthdays[j] = birthdays[j + 1];
                birthdays[j + 1] = tempb;
                
                
                student *temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;     
             }
         }    
     }     
}
