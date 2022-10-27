
#include "Student.h"
#include <iostream>
#include <string>
using std::string;

//paramterless constructor
Student::Student()
{
	this->studentID = ""; //points to variable name; "this" keyword distinguishes from parameters
	this->firstname = "";
	this->lastname = "";
	this->email = "";
	this->age = "";
	for (int i = 0; i < daystocompleteArraySize; i++) this->daystocomplete[i] = 0; //sets daystocomplete array to 0 and loops
	this->degreeprogram = DegreeProgram::SOFTWARE; //sets default value of degreeprogram

}

Student::Student(string studentID, string firstname, string lastname, string email, string age, int daystocomplete[], DegreeProgram degreeprogram) //Student constructor 
{
	this->studentID = studentID;
	this->firstname = firstname;
	this->lastname = lastname;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daystocompleteArraySize; i++) this->daystocomplete[i] = daystocomplete[i];
	this->degreeprogram = degreeprogram;
}

Student::~Student() {}; //Student destructor but doesnt do anything 


//Student getters
string Student::getstudentID() { return this->studentID; } // "this" keyword distinguishes from parameters
string Student::getFirst() { return this->firstname; }
string Student::getLast() { return this->lastname; }
string Student::getEmail() { return this->email; }
string Student::getAge() { return this->age; }
const int* Student::getDaystocomplete() { return this->daystocomplete; }
DegreeProgram Student::getDegreeProgram() { return this->degreeprogram; }

//Student setters
void Student::setstudentID(string studentID) { this->studentID = studentID; }
void Student::setFirst(string firstname) { this->firstname = firstname; }
void Student::setLast(string lastname) { this->lastname = lastname; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(string age) { this->age = age; }

//sets daystocomplete in a loop
void Student::setDaystocomplete(const int daystocomplete[])
{
	for (int i = 0; i < daystocompleteArraySize; i++) this->daystocomplete[i] = daystocomplete[i];

}
//setter that passes in a degreeprogram rather than a string
void Student::setDegreeProgram(DegreeProgram degreeprogram) { this->degreeprogram = degreeprogram; }

void Student::PrintHeader() // creates headers for roster

{
	cout << "studentID\t"; // \t seperates text by tabs
	cout << "First Name\t";
	cout << "Last Name\t";
	cout << "Email\t";
	cout << "Age\t";
	cout << "Days to Complete Program\t";
	cout << "Degree Program\t";
	cout << endl;

}

void Student::print()
{
	cout << this->studentID << '\t';
	cout << this->firstname << '\t';
	cout << this->lastname << '\t';
	cout << this->email << '\t';
	cout << this->age << '\t';
	cout << this->daystocomplete[0] << ','; //can't use pointer here
	cout << this->daystocomplete[1] << ',';
	cout << this->daystocomplete[2] << '\t';
	cout << degreeProgramStrings[(int)this->degreeprogram] << '\t';
	cout << endl;
}

//Student::~Student() {};