#include<iostream>
#include<iomanip>
#include "Student.h"
//using std::string;
using std::cout;
using std::left;
using std::setw;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0; //not sure how to set this int age for empty contrusctor

	for (int i = 0; i < daysArraySize; ++i)
	{
		this->days[i] = 0;
	}
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[])
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age; 
	for (int i = 0; i < daysArraySize; ++i)
	{
		this->days[i] = days[i]; //for days variable 
	}
}

//getters
string Student::getID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getDays()
{
	return days;
}

//setters
void Student::setID(int studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}
 
void Student::setLastName(string lastName)
{
	this->firstName = firstName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}
void Student::setCourseTime(int days[])
{
	for (int i = 0; i < daysArraySize; ++i) 
		this->days[i] = days[i];
}

void Student::Print()
{
	int* classDays = getDays();
	// play with the setw values
	cout << left << setw(5) << getID();
	cout << left << setw(15) << getFirstName();
	cout << left << setw(15) << getLastName();
	cout << left << setw(30) << getEmailAddress();
	cout << std::right << setw(5) << getAge();
	cout << std::right << setw(10) << *classDays;  
	cout << std::right << setw(10) << (*classDays + 1);
	cout << std::right << setw(10) << (*classDays + 2);
	
}

Student::~Student()
{

}
