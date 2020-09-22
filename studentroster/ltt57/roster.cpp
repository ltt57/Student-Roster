#include <iostream>
#include <iomanip>
#include <string>
#include "roster.h"
#include "degree.h"
#include "student.h"



using namespace std;

//Constructor - Empty//
Roster::Roster()
{
    this->capacity = 0;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
    this->capacity = capacity;
    this->lastIndex = -1; //Empty//
    this->classRosterArray = new Student* [capacity];
}

string Roster::classRosterArrayID(int i)
{
    return classRosterArray[i]->getStudentID();
}

void Roster::parseAdd(string row)
{
    if (lastIndex < capacity)
    {
        lastIndex++;
        
        
        int long rhs = row.find(",");
        string ID = row.substr(0, rhs);
        
        int long lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string first = row.substr(lhs, rhs - lhs);
        
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string last = row.substr(lhs, rhs - lhs);
        
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string email = row.substr(lhs, rhs - lhs);
       
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int a = stod(row.substr(lhs, rhs - lhs));
        
//Days In Course//
                       
//  daysInCourse 1 [0]  //
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        double dayA = stod(row.substr(lhs, rhs - lhs));
                  
//  daysInCourse 2 [1]  //
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        double dayB = stod(row.substr(lhs, rhs - lhs));
       
//  daysInCourse 3 [2]  //
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        double dayC = stod(row.substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string deg = row.substr(lhs, rhs - lhs);
    
        
        DegreeProgram degree;
        if (deg == "NETWORK")
        {
            degree = NETWORK;
        }
        else if (deg == "SECURITY")
        {
        degree = SECURITY;
        }
        else if (deg == "SOFTWARE")
        {
        degree = SOFTWARE;
        }
        else
        {
        cerr << "Degree Program Does Not Exist.\n";
        exit(-1);
        }
        add(ID, first, last, email, a, dayA, dayB, dayC, degree);
    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double dayA, double dayB, double dayC, DegreeProgram degree)
{
    double dayarray[Student::daysInCourseArraySize];
    dayarray[0] = dayA;
    dayarray[1] = dayB;
    dayarray[2] = dayC;
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, dayarray, degree);
}

void Roster::print_All()
{
    for (int i = 0; i <= this->lastIndex; ++i)
    {
        (this->classRosterArray)[i]->print();
    }
}

void Roster::remove(string studentID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i)
    {
        if (this->classRosterArray[i]->getStudentID() == studentID)
        {
            if (i < lastIndex)
            {
                delete this->classRosterArray[i];
                for (int j = i; j < lastIndex; ++j)
                {
                    this->classRosterArray[i] = this->classRosterArray[j + 1];
                }
            }
            else if (i == lastIndex)
            {
                delete classRosterArray[i];
            }
            lastIndex--;
            found = true;
    
            }
        }
        if (found == false)
        {
            cout << "Student ID:" << "[" << studentID << "]" <<  " Was Not Found. " << endl;
        }
}


void Roster::printAvgDaysInCourse(string studentID)
{
    for (int i = 0; i <= lastIndex; ++i)
    {
        string stuID = classRosterArray[i]->getStudentID();
        if(stuID == studentID)
            {
                double d = 0;
                for (int j = 0; j < Student::daysInCourseArraySize; ++j)
            {
                d = d + classRosterArray[i]->getDaysInCourse(j);
            }
            {
                cout << "Student ID:" << "[" << studentID << "]" << "  --->  Average Days In Course: " << setprecision(4) << (d / Student::daysInCourseArraySize) << endl;
            }
            }
        }
}

void Roster::printInvalidEmails()
{
    for (int i = 0; i <= lastIndex; ++i)
    {
        string emailex = classRosterArray[i]->getEmailAddress();
        
        if ((emailex.find("@") == string::npos) | (emailex.find(" ") != string::npos) | (emailex.find(".") == string::npos))
        {
            cout << "Invalid Emails: " << emailex << endl;
        }
    }
}
 
void Roster::printByDegreeProgram(DegreeProgram degree)
{
    for (int i = 0; i <= lastIndex; ++i)
    {
        if (this->classRosterArray[i]->getDegreeProgram() == degree) this->classRosterArray[i]->print();
    }
}

//Destructor//
Roster::~Roster()
{
    for (int i = 0; i < Student::daysInCourseArraySize; ++i)
    {
        delete classRosterArray[i];
    }
    delete classRosterArray;
}

