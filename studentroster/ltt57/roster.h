#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;



class Roster
{
public:
    
    int lastIndex;
    int capacity;       //Roster MAX Size//
    
    Student** classRosterArray;
    
    Roster();
    Roster(int capacity);
    
    string classRosterArrayID(int i);   //Student ID for AVG Days//
    
    void parseAdd(string row);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, double dayA, double dayB, double dayC, DegreeProgram degree);
    void print_All();
    void remove(string studentID);
    void printAvgDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degree);
    
   
    //Destructor//
    ~Roster();
};

