#pragma once
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include "degree.h"


using namespace std;


class Student
{
private:
  
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    
    
    int age;
    double* daysInCourse;
    
    DegreeProgram degree;
    
public:
   
    const static int daysInCourseArraySize = 3;
   
    //Constructor//
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse[], DegreeProgram degree);
    
    
    //Accessor//
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    
    int getAge();
    double getDaysInCourse(int dayarray);
    
    DegreeProgram getDegreeProgram();
    
    
    //Mutator//
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(double daysInCourse[daysInCourseArraySize]);
    void setDegreeProgram(DegreeProgram degree);
    
    void print();
    
    
    //Destructor
    ~Student();
};

