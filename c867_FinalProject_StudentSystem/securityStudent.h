#pragma once
#include<string>
#include "Student.h"

class SecurityStudent : public Student
{
public:
	SecurityStudent(); //empty constructor
	SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree degreeType);

	Degree getDegreeType(); //from virtual in student class
	void Print();

	~SecurityStudent(); //destructor
};