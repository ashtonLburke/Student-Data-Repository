#pragma once
#include <regex>
#include "SchoolRoster.h"
#include "Degree.h"
#include "Student.h"



void SchoolRoster::parse(string row) //utilizes regular expressions 
{
	cout << "PARSING \n";
	std::regex regex("\\,");
		std::vector<string> splitter(
			std::sregex_token_iterator(row.begin(), row.end(), regex, -1), std::sregex_token_iterator()
		);
DegreeProgram dp = DegreeProgram::SOFTWARE; // maintains default degreeprogram
if (splitter.at(8).back() == 'Y') dp = DegreeProgram::SECURITY;
if (splitter.at(8).back() == 'K') dp = DegreeProgram::NETWORK;
add(splitter.at(0), (splitter.at(1)), splitter.at(2), (splitter.at(3)), (splitter.at(4)), stoi(splitter.at(5)), stoi(splitter.at(6)), stoi(splitter.at(7)), dp); //uses stoi for respective integers for daystocomplete array
//tokens supplied by regex
}

//add method
void SchoolRoster::add(string studentID, string firstname, string lastname, string email, string age, int daystocomeplete1, int daystocomplete2, int daystocomeplete3, DegreeProgram dp)
{
	int daystocompleteArray[3] = { daystocomeplete1, daystocomplete2, daystocomeplete3 }; //replaces integers in array
	studentsArray[++lastIndex] = new Student(studentID, firstname, lastname, email, age, daystocompleteArray, dp);
	cout << "School Student has been successfully added to row" << lastIndex + 1 << endl; //lastIndex calls the index of last student

}


	void SchoolRoster::printALL() //creates display for all Student information
	{
		Student::PrintHeader();
		for (int i = 0; i <= SchoolRoster::lastIndex; i++) SchoolRoster::studentsArray[i]->print(); //loop print method for student data to print itself

	}
	void SchoolRoster::printByDegreeProgram(DegreeProgram dp) //prints by each student's respective degreeprgram
	{
		Student::PrintHeader();
		for (int i = 0; i <= SchoolRoster::lastIndex; i++) //loop that finds matches
			if (SchoolRoster::studentsArray[i]->getDegreeProgram() == dp) studentsArray[i]->print(); //prints matches

	}

	void SchoolRoster::printInvalidEmails() //searches and prints incorrect email inputs
	{
		for (int i = 0; i <= SchoolRoster::lastIndex; i++)
		{
			string id = SchoolRoster::studentsArray[i]->getEmail(); //get student email
			if (id.find('@') == string::npos || id.find('.') == string::npos || id.find(' ') != string::npos) //searches email for typos; == for absent characters, != for incorrect present characters
					cout << id << " is not valid. " << endl; //displays incorrect emails
		}
	}

	void SchoolRoster::printAverageDays(string studentID) //calculates and prints average days remaining per class
	{
		for (int i = 0; i <= SchoolRoster::lastIndex; i++)  //searches for matching student id
		{
			if (studentsArray[i]->getstudentID() == studentID) //IF match then show  average days to complete
			{
				cout << studentID << ":";
				cout << (studentsArray[i]->getDaystocomplete()[0] +
					studentsArray[i]->getDaystocomplete()[1] +
					studentsArray[i]->getDaystocomplete()[2]) / 3.0 << endl; //average calculation

			}

		}

	};

	void SchoolRoster::removeStudentbyID(string studentID) //searches for then deletes student by their respective ID
	{
		bool success = false;
		for (int i = 0; i <= SchoolRoster::lastIndex; i++) //searches student data
		{
			if (studentsArray[i]->getstudentID() == studentID)
			{
				success = true;
				Student* temp = studentsArray[i]; //switches tudent with last student
				studentsArray[i] = studentsArray[numStudents - 1];
				studentsArray[numStudents - 1] = temp;
				SchoolRoster::lastIndex--; //knocks off last student (sought after student for removal)
			}
		}
		if (success)
		{
			cout << "Student " << studentID << " has been successfully removed!" << endl;
			printALL();
		}
		else cout << "Student " << studentID << " cannot be found!" << endl; //verifies student was removed (or there was a complete failure in finding respective student)
	}

	SchoolRoster::~SchoolRoster() //destructor loop that utilizes numStudents to delete each and every student
	{
		for (int i = 0; i < numStudents; i++)
		{
			cout << "Destructor asked for " << studentsArray[i]->getstudentID() << endl;

			studentsArray[i] = nullptr; //sets student array to null post-deletion

		}




	}


