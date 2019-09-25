#pragma once
#include <string>
#include "Student.h"

class SoftwareStudent : public Student //from student class
{
public:// not sure about this yet
	SoftwareStudent();
	SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree degreeType);

	Degree getDegreeType(); //from virtual in student class
	void Print();

	~SoftwareStudent();
};