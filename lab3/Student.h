#include "myDate.h"
#include <string>
using namespace std;

struct Student
{
   string name;
   int identificationNumber;
   int grade;
   myDate birthDay;
};

void setStudentData(Student &stud, string name, int identificationNumber, int grade, myDate birthday);
int getStudentID(Student &stud);
int getStudentBirthday(Student &stud);
void populate(Student (stud[]) );
void printStudent(Student &stud);
void sortID(Student **ptr);
void sortAge(Student **ptr);
