/*
Author: Sohaib Nadeem
Student Number: 100621437
*/
#include<fstream>
#include<string>
#include"Student.h"

int Student::studentNo = 0; //set student counter

//constructor definition
Student::Student(std::string newName, Date newDob, int newSin, std::string newMajor, int newNumberCourses, std::string newDepartment, bool newAgreeToTeach)
	:name(newName), dob(newDob), sin(newSin), major(newMajor), numberCourses(newNumberCourses), department(newDepartment), agreeToTeach(newAgreeToTeach) {}

//overloaded operator definitions
std::ostream & operator<<(std::ostream & output, const Student & student) //outputs a student object in a formatted way
{
	bool tempAgreeToTeach;
	tempAgreeToTeach = student.getAgreeToTeach(); //store bool so it can be outputted as alpha characters
	output << "\n################ STUDENT ################"<<"\nStudent Name: " << student.getName() << "\nDOB: " << student.getDob() << "\nSIN: " << student.getSin() <<
		"\nMajor: " << student.getMajor() << "\nNumber of Courses: " << student.getNumberCourses() << "\nDepartment " << student.getDepartment()
		<< "\nAgree to teach: " << std::boolalpha << tempAgreeToTeach << "\n****************************************\n";
	return output;
}
std::istream & operator>>(std::istream & input, Student & student) //prompt user for and store student object information inside student, with exception handling
{
	Date tempDob;
	std::string tempName;
	long int tempSin;
	std::string tempMajor;
	int tempNumberCourses;
	std::string tempDepartment;
	char tempAgreeToTeach;

	//GET AND STORE STUDENT NAME
		std::cin.ignore();
		std::cout << "Enter student name: ";
		std::getline(std::cin, tempName);
		student.setName(tempName);

	//GET AND STORE/EXIT (valid/invalid) STUDENT DOB
		std::cout << "Enter student date of birth: (ie. DD MM YY) "; 
		try 
		{
			std::cin >> tempDob;
			if (std::cin.fail())
				throw "Error: Input does not match required data type!";
		}
		catch (const char* ex) { std::cerr << "Invalid date entry! Enter date as:  DD MM YY \n"; system("pause"); exit(1); }
		student.setDob(tempDob);

	//GET AND STORE/EXIT (valid/invalid) STUDENT SIN
		std::cout << "Enter student SIN: (ie. 123456789) "; 
		try
		{
			std::cin >> tempSin;
			if (std::cin.fail())
				throw "Error: Input does not match required data type!";
		}
		catch (const char* ex) { std::cerr << "Invalid SIN entry! Enter the SIN in format: 123456789 \n"; system("pause"); exit(1); }
		student.setSin(tempSin);

	//GET AND STORE STUDENT MAJOR
		std::cout << "Enter student major: (ie. Mechatronics) ";
		std::cin >> tempMajor;
		student.setMajor(tempMajor);

	//GET AND STORE/EXIT (valid/invalid) STUDENT NUMBER OF COURSES
		std::cout << "Enter student number of courses: (ie. 5) ";
		try 
		{
			std::cin >> tempNumberCourses;
			if (std::cin.fail())
				throw "Error: Input does not match required data type!";
		}
		catch (const char* ex) { std::cerr << "Invalid course number entry! Enter an integer! (ie. 5) \n"; system("pause"); exit(1); }
		student.setNumberCourses(tempNumberCourses);

	//GET AND STORE STUDENT DEPARTMENT
		std::cout << "Enter student department: (ie. FEAS) ";
		std::cin >> tempDepartment;
		student.setDepartment(tempDepartment);

	//GET AND SET STUDENT AGREE TO TEACH STATUS IF VALID ENTRY MADE (handles lowercase and uppercase entry from user as well as exceptions)
		bool y = true;
		bool n = false;
		std::cout << "Agree to teach student? (ie. Y/N) ";
		try
		{
			std::cin>>tempAgreeToTeach;
			if (std::cin.fail())
				throw "Error: Invalid input!";
		}
		catch (const char* ex) { std::cerr << "Invalid entry! You are to enter Y or N! "; system("pause"); exit(1); }

	if (toupper(tempAgreeToTeach) == 'Y')
			student.setAgreeToTeach(y);
		else if (toupper(tempAgreeToTeach) == 'N')
			student.setAgreeToTeach(n);
		else
		{
			std::cerr << "Invalid input! Enter either Y or N!\n";
			system("pause");
			exit(1);
		}
	//ADD STUDENT INFORMATION (if all above is successful) TO TEXT FILE
		std::ofstream studentListOut("Students.txt", std::ios::app); //append mode by default, to clear student list, delete Students.txt file
		if (studentListOut.is_open())//file error checking
		{
			studentListOut << "\n################ STUDENT ################" << "\nStudent Name: " << student.getName() << "\nDOB: " << student.getDob() << "\nSIN: " << student.getSin() <<
				"\nMajor: " << student.getMajor() << "\nNumber of Courses: " << student.getNumberCourses() << "\nDepartment " << student.getDepartment()
				<< "\nAgree to teach: " << std::boolalpha << tempAgreeToTeach << "\n****************************************\n";
			studentListOut.close();
		}
		else
		{
			std::cerr << "The Students.txt file could not be written to. Please delete Students.txt file and re-run program.";
			system("pause");
			exit(1);
		}
	return input;
}
//getter definitions
std::string Student::getMajor() const { return major; }
std::string Student::getDepartment() const { return department; }
int Student::getNumberCourses() const { return numberCourses; }
int Student::getAgreeToTeach() const { return agreeToTeach; }
int getStudentNo() { return Student::studentNo; }
std::string Student::getName() const { return name; }
Date Student::getDob() const { return dob; }
int Student::getSin() const { return sin; }

//setter definitions
void Student::setMajor(std::string& newMajor) { major = newMajor; }
void Student::setDepartment(std::string& newDepartment) { department = newDepartment; }
void Student::setNumberCourses(int& newNumberCourses) { numberCourses = newNumberCourses; }
void Student::setAgreeToTeach(bool& newAgreeToTeach) { agreeToTeach = newAgreeToTeach; }
void Student::setName(std::string& newName) { name = newName; }
void Student::setDob(Date& newDob) { dob = newDob; }
void Student::setSin(long int& newSin) { sin = newSin; }