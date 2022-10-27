// main
//c867 School Roster Project
// by Ashton Burke 
#include "SchoolRoster.h"
using namespace std;

int main()
    {

        {
            cout << "C867 Scripting and Programming Applications\n Language: C++\n Student id: 010071775\n Name: Ashton Burke" << endl;
            
        }
//string of student data that needs to be parsed
        const string studentData[] =

        { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
          "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
          "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
          "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
          "A5,Ashton,Burke,abur596@wgu.edu,26, 10,20,30,SOFTWARE"
        };
        const int numStudents = 5; //size of student aarray

        SchoolRoster schoolroster; //local variable designator followed by student data assembler
        for (int i = 0; i < numStudents; i++) schoolroster.parse(studentData[i]);
        cout << "Presenting all student data:" << endl;
        schoolroster.printALL();

        //assembles and presents student data by respective degree programs

        for (int i = 0; i < 3; i++)
        {

            cout << "Presenting degrees based by respective program:" << degreeProgramStrings[i] << endl;
            schoolroster.printByDegreeProgram((DegreeProgram)i);

        }
        //assembles and presents emails that had been inputed incorrectly

        cout << "Presenting all students with improper emails:" << endl;
        schoolroster.printInvalidEmails();

        cout << "Presenting average days to complete each class: " << endl;
        for (int i = 0; i < numStudents; i++)
        
            schoolroster.printAverageDays(schoolroster.studentsArray[i]->Student::getstudentID());
        
        
    //performs designated student withdrawl 
        cout << "Withdrawing student A 1:" << endl;
        schoolroster.removeStudentbyID("A1");
    //ensures student was successfully withdrawn with displayed error message
        cout << "Withdrawing student A 1:" << endl;
        schoolroster.removeStudentbyID("A1");
    //announces destructors
        cout << "Finalized. Destructors will operate once application is exited." << endl;
        return 0;
}