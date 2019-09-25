#pragma once
#include <string>
#include <iostream>
#include "Student.h"
#include "securityStudent.h"
#include"networkStudent.h"
#include "softwareStudent.h"
#include "degree.h"

class Roster {
private:
	int lastIndex; //use as counter
	int rosterSize; //max size of roster
	Student** students; /*students is an array of pointers to students, hence the **.
					 	  This array stores the addresses of the objects when they are created*/
public:
	Roster(); //empty constructor
	Roster(int rosterSize); // sets max size

	Student* getStudentAt(int lastIndex);
	void parseThenAdd(string dataString);
	void add(string sid, string sfirstname, string slastname, string semailaddress, int sage, int sdays1, int sdays2, int sdays3, Degree degreetype);
	void printAll(); //use Student's Print() method to print all students on roster
	bool remove(string studentID);
	void printInvalidEmails();
	void printAvgDays(string studentID);
	void printDegreeProgram(Degree s); //doublecheck
	~Roster();
};