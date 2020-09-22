#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
#include "student.h"



using namespace std;


//Constructor - Empty//
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysInCourse = new double[daysInCourseArraySize];
    for (int i = 0; i < daysInCourseArraySize; ++i)
                this->daysInCourse[i] = 0;
}


Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse[], DegreeProgram degree)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse = new double[daysInCourseArraySize];
    for (int i = 0; i < daysInCourseArraySize; ++i) this->daysInCourse[i] = daysInCourse[i];
    this->degree = degree;
}

//Accessor//
string Student::getStudentID()
{
    return studentID;
}

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}

string Student::getEmailAddress()
{
    return emailAddress;
}

int Student::getAge()
{
    return age;
}

double Student::getDaysInCourse(int dayarray)
{
    return daysInCourse[dayarray];
}

DegreeProgram Student::getDegreeProgram()
{
     return degree;
}


//Mutator//
void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDaysInCourse(double daysInCourse[daysInCourseArraySize])
{
    for (int i = 0; i < daysInCourseArraySize; i++)
    {
        this->daysInCourse[i] = daysInCourse[i];
    }

}

void Student::setDegreeProgram(DegreeProgram degree)
{
    this->degree =  degree;
}

void Student::print()
{
    cout << left << setw(5) << studentID;
    cout << left << setw(10) <<  "First Name: " << firstName << "\t";
    cout << left << setw(12) << "Last Name: " << lastName << "\t";
    cout << left << setw(5) << "Age: " << age << "\t";
    cout << left << setw(3) << "daysInCourse: " << "(" << daysInCourse[0];
    cout << left << setw(3) << ", " << daysInCourse[1];
    cout << left << setw(3) << ", " << daysInCourse[2] << ")" << "\t";
    cout << left << setw(5) << "Degree Program: " << degreeProgramStrings[getDegreeProgram()];
    cout << endl;
}

//Destructor//
Student::~Student()
{
    if (this->daysInCourse !=nullptr)
       {
           delete[] this->daysInCourse;
           this->daysInCourse = nullptr;
       }
}
