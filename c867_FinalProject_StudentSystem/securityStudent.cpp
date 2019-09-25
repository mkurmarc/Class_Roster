#include <iostream>
#include "securityStudent.h"
#include <iomanip>
using std::cout;

SecurityStudent::SecurityStudent():Student()
{
	degreeType = Security;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree degreeType)
	:Student(studentID, firstName, lastName, emailAddress, age, days)
{
	degreeType = Security;
}

Degree SecurityStudent::getDegreeType()
{
	return Security; 
}

void SecurityStudent::Print()
{
	this->Student::Print(); // from the student class
	cout << std::right << std::setw(15) << "SECURITY\n";
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student(); //objects shold not destry themselves. They only destry what they dynamically make for themselves : remove later
}