/*
Author: Sohaib Nadeem
Student Number: 100621437
*/
#include"Professor.h"
#include"Date.h"

//constructor definition
Professor::Professor(std::string newName, Date newDob, int newSin, std::string newOffice, int newNumberOfCourses, std::string newEmploymentStatus)
	:name(newName), dob(newDob), sin(newSin), office(newOffice), numberOfCourses(newNumberOfCourses), employmentStatus(newEmploymentStatus){}

//overloaded operators definition
std::ostream& operator<<(std::ostream& output, const Professor& professor) //Formatted output of professor object
{
	output <<"%%%%%%%%%%%%%%% PROFESSOR %%%%%%%%%%%%%%%\n"<<"Professor Name: " << professor.getName() << "\nDOB: " << professor.getDob() << "\nSIN: " << professor.getSin() <<
		"\nOffice: " << professor.getOffice() << "\nNumber of Courses: " << professor.getNumberOfCourses() << "\nEmployment Status: " << professor.getEmploymentStatus() << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	return output;
}
std::istream& operator>>(std::istream& input, Professor& professor) //Asks user for input, and assigns it to a professor object, includes exception handling
{
	Date tempDob;
	std::string tempName;
	int tempSin;
	std::string tempOffice;
	int tempNumberOfCourses;
	std::string tempEmploymentStatus;
	
	//GET AND STORE PROFESSOR NAME
	std::cin.ignore();
	std::cout << "Enter professor name: ";
	std::getline(std::cin, tempName);
	professor.setName(tempName);

	//GET CHECK AND EXIT/STORE (valid/invalid) DOB for PROFESSOR OBJECT
	std::cout << "Enter professor date of birth: (ie. DD MM YY) "; 
	try
	{
		std::cin >> tempDob;
		if (std::cin.fail())
			throw "Error: Input does not match required data type!";
	}
	catch (const char* ex) { std::cerr << "Invalid date entry! Enter date as:  DD MM YY \n"; system("pause"); exit(1); }
	professor.setDob(tempDob);


	//GET CHECK AND EXIT/STORE (valid/invalid) SIN for PROFESSOR OBJECT
	std::cout << "Enter professor SIN: (ie. 123456789) ";

	try 
	{
		std::cin >> tempSin;
		if (std::cin.fail())
			throw "Error: Input does not match required data type!";
	}
	catch (const char* ex) { std::cerr << "Invalid SIN entry! Enter the SIN in format: 123456789 \n"; system("pause"); exit(1); }
	professor.setSin(tempSin);

	//GET AND STORE PROFESSOR OFFICE
	std::cout << "Enter professor office: (ie. UA4240) ";
	std::cin >> tempOffice;
	professor.setOffice(tempOffice);

	//GET CHECK AND EXIT/STORE (valid/invalid) NUMBER OF COURSES for PROFESSOR OBJECT
	std::cout << "Enter professor number of courses: (ie. 3) ";
	try {
		std::cin >> tempNumberOfCourses;
		if (std::cin.fail())
			throw "Error: Input does not match required data type!";
	}
	catch (const char* ex) { std::cerr << "Invalid course number entry! Enter an integer! (ie. 3) \n"; system("pause"); exit(1); }
	professor.setNumberOfCourses(tempNumberOfCourses);

	//GET AND STORE PROFESSOR EMPLOYMENT STATUS
	std::cout << "Enter professor employment status: (ie. Tenure) ";
	std::cin >> tempEmploymentStatus;
	professor.setEmplyomentStatus(tempEmploymentStatus);
	return input;
}

//getter definitions
std::string Professor::getOffice() const { return office; }
int Professor::getNumberOfCourses() const{ return numberOfCourses; }
std::string Professor::getEmploymentStatus() const { return employmentStatus; }
std::string Professor::getName() const { return name; }
Date Professor::getDob() const { return dob; }
int Professor::getSin() const { return sin; }

//setter definitons
void Professor::setOffice(std::string& newOffice) { office = newOffice; }
void Professor::setNumberOfCourses(int& newNumberOfCourses) { numberOfCourses = newNumberOfCourses; }
void Professor::setEmplyomentStatus(std::string &  newEmploymentStatus){ employmentStatus = newEmploymentStatus;}
void Professor::setName(std::string & newName) { name = newName; }
void Professor::setDob(Date& newDob) { dob = newDob; }
void Professor::setSin(int& newSin) { sin = newSin; }