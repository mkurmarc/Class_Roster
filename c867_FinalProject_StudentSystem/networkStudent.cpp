#include <iostream>
#include "networkStudent.h"

using std::cout; //use std on another way through out the code

NetworkStudent::NetworkStudent() :Student()
{
	degreeType = Network;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree degreeType)
	: Student(studentID, firstName, lastName, emailAddress, age, days)
{
	degreeType = Network;
}

Degree NetworkStudent::getDegreeType() //from virtual in student class
{
	return Network;
}

void NetworkStudent::Print()
{
	this->Student::Print(); // from the student class
	cout << std::right << std::setw(15) << "NETWORK\n"; 
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}