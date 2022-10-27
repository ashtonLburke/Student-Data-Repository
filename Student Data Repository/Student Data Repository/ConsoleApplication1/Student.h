#ifndef Student_h
#define Student_h

#pragma once
#include <iostream>
#include <iomanip>
#include "Degree.h"

using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

class Student
{
public: 
	const static int daystocompleteArraySize = 3; //array is a constant

private: //made private to prevent any fumbling of student data
	string studentID;
	string firstname;
	string lastname;
	string email;
	string age;
	int daystocomplete[daystocompleteArraySize];
	DegreeProgram degreeprogram;
public: //Student methods
	Student();

	//Student constructor
	Student(string studentID, string firstname, string lastname, string email, string age, int daystocomplete[], DegreeProgram degreeprogram);
	
	~Student();

	//getters
	string getstudentID();
	string getFirst();
	string getLast();
	string getEmail();
	string getAge();
	const int* getDaystocomplete();
	DegreeProgram getDegreeProgram();

	//setters
	void setstudentID(string studentID);
	void setFirst(string firstname);
	void setLast(string lastname);
	void setEmail(string email);
	void setAge(string age);
	void setDaystocomplete(const int daystocomplete[]);
	void setDegreeProgram(DegreeProgram dp);

	static void PrintHeader(); //prints headers of each data category 

	void print(); //prints respective student's data
};

#endif