#pragma once
#include <string>
#include <iomanip>
#include "Student.h"

class NetworkStudent : public Student //from student class
{
public: // not sure yet
	NetworkStudent();
	NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree degreeType);

	Degree getDegreeType(); //from virtual in student class
	void Print();

	~NetworkStudent();
};