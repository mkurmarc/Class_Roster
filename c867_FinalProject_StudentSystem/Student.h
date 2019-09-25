#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student
{	
public:
	const static int daysArraySize = 7; //double check

protected: //definition: accessible in the class that defines them and in other classes which inherit from that class.
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[daysArraySize]; // double check
	Degree degreeType; // double check - define in subclass

public:
	Student(); //empty constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[]);    

	//getters
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	virtual Degree getDegreeType() = 0; //virtual function; cannot initiate a Student object

	//setters
	void setID(int studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setCourseTime(int days[]);

	virtual void Print() = 0; //virtual fucntion

	~Student(); //destructor

};

