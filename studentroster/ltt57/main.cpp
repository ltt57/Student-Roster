#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"


using namespace std;

int main()
{

    const int numStudents = 5;


    string studentData[numStudents] =

    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Lucy,Tran,ltran57@wgu.edu,22,12,5,18,SOFTWARE"
    };

        cout << "Course: C867 - Scripting and Programming Application" << endl;
        cout << "Programming Language: C++" << endl;
        cout << "Name: Lucy Tran" << endl;
        cout << "StudentID: 001360516" << endl << endl << endl;
     
        Roster* classRoster = new Roster(numStudents);
        
        cout << "Parsing Data-- " << endl;
        for (int i = 0; i < numStudents; ++i)
        {
            classRoster->parseAdd(studentData[i]);
        }
        
        cout << "Complete~" << endl << endl;
        cout << endl;
    
        cout << "Displaying All Students: " << endl;
       
        //All students in roster//
        classRoster->print_All();
        
        cout << endl << endl << endl;
        cout << "Displaying Invalid Emails: " << endl;
        classRoster->printInvalidEmails();
      
        cout << endl;
        cout << "Displaying Average Days For Students: " << endl;
        for (int i = 0; i < numStudents; ++i)
        {
            classRoster->printAvgDaysInCourse(classRoster->classRosterArrayID(i));
        }
        cout << endl << endl << endl;
        
        cout << "Displaying Roster For Degree: Software \n";
        {
            classRoster->printByDegreeProgram(SOFTWARE);
        }
        cout << endl << endl;
    
        cout << "Removing Student:" << "[" << "A3" << "]" << endl;
        classRoster->remove("A3");
        cout << "Complete~ " << endl;
        cout << endl << endl;
    
        cout << "Displaying Roster: " << endl;
        classRoster->print_All();
        cout << endl << endl;
        
        cout << "Removing Student:" << "[" << "A3" << "]" << endl;
        classRoster->remove("A3");
        cout << "Complete~ " << endl << endl;
    
     
        return 0;
}

