#include <iostream>
#include "softwareStudent.h"
#include <iomanip>
using std::cout; //use std on another way through out the code

SoftwareStudent::SoftwareStudent() : Student()
{
	degreeType = Software;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree degreeType)
	: Student(studentID, firstName, lastName, emailAddress, age, days)
{
	degreeType = Software;
}

Degree SoftwareStudent::getDegreeType() //from virtual in student class
{
	return Software;
}

void SoftwareStudent::Print()
{
	this->Student::Print(); // from the student class
	cout << std::right << std::setw(15) << "SOFTWARE\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}
