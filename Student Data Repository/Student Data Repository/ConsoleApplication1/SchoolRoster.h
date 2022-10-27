#pragma once
#include <regex>
#include "Student.h"
#ifndef SchoolRoster_h
#define SchoolRoster_h

class SchoolRoster
{
public:
	int lastIndex = -1; // starts the index at none
	const static int numStudents = 5; 
	Student* studentsArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	
	

public:


	void add(string ssID, string ssFirst, string ssLast, string ssEmail, string ssAge, int ssDaysto1, int ssDaysto2, int ssDaysto3, DegreeProgram dp);
	void parse(string row); //parses by using regular expression's 'regex' to split data up
	void printALL(); //prints all student data
	void printByDegreeProgram(DegreeProgram dp); //prints student data by respective degree program
	void printInvalidEmails(); //searches student emails and prints any with incorrect inputs
	void printAverageDays(string studentID); //calculates and prints average days remaining of classes per respective student
	void removeStudentbyID(string studentID); //searches and withdrawals designated student

	~SchoolRoster(); //SchoolRoster's destructor
};


#endif