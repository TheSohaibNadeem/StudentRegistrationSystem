/*
Author: Sohaib Nadeem
*/
#include<iostream>
#include<fstream>
#include"Course.h"
int Course::courseNo = 0;
//consturctor definition
Course::Course(int newCourseNo, std::string newCourseName, int newCredits): courseName(newCourseName), credits(newCredits){}

//overloaded operators definitions
std::ostream & operator<<(std::ostream & output, const Course & course)
{
	output << "$$$$$$$$$$$$$$$ COURSE $$$$$$$$$$$$$$$\n" << course.getCourseName() << " " << course.getCourseNo()
		<< " - Total Credits: " << course.getCredits() << "\n";
	return output;
}
std::istream & operator>>(std::istream & input, Course & course)
{
	std::string tempCourseName;
	int tempCourseNo;
	int tempCredits;

	//GET COURSE NAME AND STORE
	std::cout << "Enter Course Name: (ie. INFR) ";
	std::cin >> tempCourseName;
	course.setCourseName(tempCourseName);

	//GET AND CHECK COURSE NUMBER AND STORE/EXIT (valid/invalid)
	std::cout << "Enter course number: (ie. 2140) ";
		try {
		std::cin >> tempCourseNo;
		if (std::cin.fail())
			throw "Error: Input does not match required data type!";
	}
	catch (const char* ex) { std::cerr << "Invalid course number! Enter the course number in format: 2140 \n"; system("pause"); exit(1); }
	course.setCourseNo(tempCourseNo);

	//GET AND CHECK CREDITS AND STORE/EXIT (valid/invalid) only whole number course credits allowed (ie type int) decimals will be truncated
	std::cout << "Enter course credits: (ie. 3) ";
	try {
		std::cin >> tempCredits;
		if (std::cin.fail())
			throw "Error: Input does not match required data type!";
	}
	catch (const char* ex) { std::cerr << "Invalid credits! Credits must be entered as whle number in format: 3 \n"; system("pause"); exit(1); }
	course.setCredits(tempCredits);
	
	//Store courses in Courses.txt if all above was successful
	std::ofstream courseFileOut("Courses.txt", std::ios::app); //courses are appended, to delete (clear courses) delete Courses.txt file
	course.setCourseNo(tempCourseNo);
	if (courseFileOut.is_open()) //file error checking
	{
		courseFileOut << "$$$$$$$$$$$$$$$ COURSE $$$$$$$$$$$$$$$\n" << course.getCourseName() << " " << course.getCourseNo()
			<< " - Total Credits: " << course.getCredits() << "\n";
		courseFileOut.close();
	}
				else
				{
					std::cerr << "Error writing to course file. Please delete Students.txt and re-run program.";
					system("pause");
					exit(1);
				}
	return input;
}

//getter definitions
bool Course::hasPrequisite(Course& course) const
{
	for (int i = 0; i < Course::preReqs.size(); i++)
		if (Course::preReqs[i].getCourseName() == course.getCourseName() && Course::preReqs[i].getCourseNo() == course.getCourseNo() && Course::preReqs[i].getCredits() == course.getCredits())
		{
			return true;
			break;
		}
		else
			return false;
}
int Course::getCourseNo() const { return courseNo; }
std::string Course::getCourseName() const { return courseName; }
int Course::getCredits() const { return credits; }

//setter definitions
void Course::addPrerequisite(Course& newPreReq) { Course::preReqs.push_back(newPreReq); } 
void Course::setCourseNo(int& newCourseNo) { courseNo = newCourseNo; }
void Course::setCourseName(std::string& newCourseName) { courseName = newCourseName; }
void Course::setCredits(int& newCredits) { credits = newCredits; }
