#include "roster.h"
using std::cout;
using std::cerr;


Roster::Roster() //empty constructor
{
	this->rosterSize = 0;
	this->lastIndex = -1; //empty
	this->students = nullptr;
}

Roster::Roster(int rosterSize)//constructor with parameter
{
	this->rosterSize = rosterSize;
	this->lastIndex = -1;
	this->students = new Student*[rosterSize];
}

Student* Roster::getStudentAt(int index)
{
	return students[index];
}

void Roster::add(string sid, string sfirstname, string slastname, string semailaddress, int sage, int sdays1, int sdays2, int sdays3, Degree degreetype)
{
	int studentDays[Student::daysArraySize];
	studentDays[0] = sdays1;
	studentDays[1] = sdays2;
	studentDays[2] = sdays3;

	if (degreetype == Software)
	{
		students[lastIndex] = new SoftwareStudent(sid, sfirstname, slastname, semailaddress, sage, studentDays, degreetype);
	}
	else if(degreetype == Network)
	{
		students[lastIndex] = new NetworkStudent(sid, sfirstname, slastname, semailaddress, sage, studentDays, degreetype);
	}
	else if (degreetype == Security)
	{
		students[lastIndex] = new SecurityStudent(sid, sfirstname, slastname, semailaddress, sage, studentDays, degreetype);
	}		
}

void Roster::parseThenAdd(string row) // move to about row 28 - double check location
{
	if (lastIndex < rosterSize)
	{
		lastIndex++;
		Degree degreeType;

		if (row.at(row.size() - 1) == 'E')
		{
			degreeType = Software;
		}

		else if (row.at(row.size() - 1) == 'K')
		{
			degreeType = Network;
		}

		else if (row.at(row.size() - 1) == 'Y')
		{
			degreeType = Security;
		}

		else//debug code - check 
		{
			cerr << "BAD DEGREE TYPE..\n";
			exit(-1);
		}

		// student ID
		int endData = row.find(","); //returns index number of comma in row string
		string sID = row.substr(0, endData); //temp holding variable for student ID parsed fro mthe string

		// first name
		int startData = endData + 1; //new starting index point
		endData = row.find(",", startData);
		string sFirstName = row.substr(startData, endData - startData);//temp variable

		// last name
		startData = endData + 1;
		endData = row.find(",", startData);
		string sLastName = row.substr(startData, endData - startData);//temp variable

		//email address
		startData = endData + 1;
		endData = row.find(",", startData);
		string sEmailAddress = row.substr(startData, endData - startData); //temp variable

		//age
		startData = endData + 1;
		endData = row.find(",", startData);
		int sAge = stoi(row.substr(startData, endData - startData)); //temp variable

		//days - first data entry
		startData = endData + 1;
		endData = row.find(",", startData);
		int sDays1 = stoi(row.substr(startData, endData - startData)); //temp variable

		//days - second data entry
		startData = endData + 1;
		endData = row.find(",", startData);
		int sDays2 = stoi(row.substr(startData, endData - startData)); //temp variable

		//days - third data entry
		startData = endData + 1;
		endData = row.find(",", startData);
		int sDays3 = stoi(row.substr(startData, endData - startData)); //temp variable

		add(sID, sFirstName, sLastName, sEmailAddress, sAge, sDays1, sDays2, sDays3, degreeType);

	}

	else
	{
		cerr << "ERROR! MAX CAP REACHED! EXITING...";
		exit(-1);
	}
}

// use for loop to go thru the array and print them
void Roster::printAll()
{
	for (int i = 0; i <= lastIndex; ++i) //lastIndex has increased via add function
	{
		this->students[i]->Print();
	}
}

bool Roster::remove(string ID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (this->students[i]->getID() == ID)
		{
			found = true;

			delete this->students[i]; //delete double check students
			this->students[i] = this->students[lastIndex];
			--lastIndex;

		}

	}

	if (found == false)
		{
		cout << "ERROR!!!";
		}

	return found;
}

void Roster::printInvalidEmails()
{
	
	cout << "Displaying invalid email address entries:\n";
	
	bool invalid = false;
	char at = '@';
	char period = '.';
	char space = ' ';
	for (int i = 0; i <= lastIndex; ++i)
	{
		
		string e = students[i]->getEmailAddress();
		if (e.find(at) == string::npos || e.find(period) == string::npos || e.find(space) != string::npos)// search for @, . , and make sure there are no spaces in email string
		{
			invalid = true;
			cout << "Student " << students[i]->getFirstName() << " " << students[i]->getLastName() << " email " << e << " is not valid.";
		}
		if (invalid)
		{
			cout << "\n";
		}
	
	}
	if (!invalid)
	{
		cout << "NONE\n";
	}
}


void Roster::printAvgDays(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (this->students[i]->getID() == studentID)
		{
			found = true;
			int* s = students[i]->getDays();
			//cout << s[1] << " ";
			cout << "Average days in course for student " << studentID << " is " << (s[0] + s[1] + s[2]) / 3 << "\n";
		}
	}
	if (!found)
	{
		cout << "Student not found\n";
	}
}

void Roster::printDegreeProgram(Degree d)
{
	cout << "Printing student of degree type " << degreeTypeStrings[d] << "\n";
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->students[i]->getDegreeType() == d)
		{
			this->students[i]->Print();
		}
	}
}


Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; ++i)
	{
		delete this->students[i];
	}
	delete students;
}

////////////////MAIN BELOW///////////////////

int main()
{
	cout << "C867 Acripting and Programming - Applications, C++ programming language, Student ID: 787989, Marc T. Rios \n";

	int numStudents = 5;

	string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",//index 0 
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Marc,Rios,mrios38@wgu.edu,29,49,55,40,SOFTWARE"//index 4 
	};

	Roster* classRoster = new Roster(numStudents); // always DELETE dynamic objects

	cout << "Parsing and adding as you read this:";
	for (int i = 0; i < numStudents; ++i)	
	{
		classRoster->parseThenAdd(studentData[i]);
	}

	cout << "FINISHED.\n";
	cout << "Displaying student roster:\n";
	classRoster->printAll(); // "classRoster.printAll()"
	cout << "\n";

	
	classRoster->printInvalidEmails(); // print invalid emails

	cout << "Printing the average days to complete a course:\n"; //print avg days in course
	for (int i = 0; i < numStudents; ++i)
	{
		classRoster->printAvgDays(classRoster->getStudentAt(i)->getID()); 
	}
	cout << "\n";

	cout << "Printing by degree program:\n";
	classRoster->printDegreeProgram((Degree)2);


	cout << "\nRemoving A3..\n"; // remove A3
	if (classRoster->remove("A3"))
	{
		classRoster->printAll();
		--numStudents;
	}
	else
	{
		cout << "Student not found!\n";
	}

	cout << "\nRemoving A3..\n"; // remove A3 again
	if (classRoster->remove("A3"))
	{
		classRoster->printAll();
	}
	else
	{
		cout << "Student not found!\n";
	}
	
	system("pause");
	return 0;
	//destructor called outside of main
}