/*
Author: Sohaib Nadeem
Student Number: 100621437
*/
#include<iostream>
#include"Student.h"
#include "Section.h"
#include"Course.h"

//constructor definition
Section::Section(int newCourseNo, std::string newCourseName, int newCredits, int newSectionNo, std::string newDayOfWeek, int newTimeOfDay, std::string newRoom, int newSeatingCapacity)
	:sectionNo(newSectionNo), dayOfWeek(newDayOfWeek), timeOfDay(newTimeOfDay), room(newRoom),seatingCapacity(newSeatingCapacity){}

//overloaded operator definitions
std::ostream & operator<<(std::ostream & output, const Section & section)//outsputs formatted section information
{
	output << "/////////////// SECTION ///////////////\nCourse: " << section.getCourseName() << " " << section.getCourseNo()
		<< "\nTotal Credits: " << section.getCredits() << "\nSection Number: " << section.getSectionNo() << "\n" << section.getDayOfWeek()
		<< "'s at " << section.getTimeOfDay() << "hrs\nRoom: " << section.getRoom() << "\nSeating Capacity: " << section.getSeatingCapacity();
	return output;
}
std::istream & operator>>(std::istream & input, Section &section) //prompts user for section information, stores in section object 
{
	std::string tempCourseName;
	int tempCourseNo;
	int tempCredits;
	int tempSectionNo;
	std::string tempDayOfWeek;
	int tempTimeOfDay;
	std::string tempRoom;
	int tempSeatingCapacity;

	//GET AND STORE COURSE NAME
	std::cout << "Enter course name: (ie. INFR)";
	std::getline(std::cin, tempCourseName);
	section.Course::setCourseName(tempCourseName);
	
	//GET AND STORE COURSE NUMBER IF VALID ELSE EXIT
	std::cout << "Enter course number: (ie. 2140) ";
	try 
	{
		std::cin >> tempCourseNo;
		if (std::cin.fail())
			throw "Error: Input does not match required data type!";
	}
	catch (const char* ex) { std::cerr << "Invalid course number! Enter course number as: 2140 \n"; system("pause"); exit(1); }
	section.Course::setCourseNo(tempCourseNo);

	//GET AND STORE COURSE CREDITS IF VALID ELSE EXIT
	std::cout << "Enter course credits: (ie. 3) ";
	try 
	{
		std::cin >> tempCredits;
		if (std::cin.fail())
			throw "Error: Input does not match required data type!";
	}
	catch (const char* ex) { std::cerr << "Invalid credits! Enter the credits in the following format: 3 \n"; system("pause"); exit(1); }
	section.Course::setCredits(tempCredits);

	//GET AND STORE COURSE SECTION IF VALID ELSE EXIT
	std::cout << "Enter section number: (ie. 2) ";
	try 
	{
		std::cin >> tempSectionNo;
		if (std::cin.fail())
			throw "Error: Input does not match required data type!";
	}
	catch (const char* ex) { std::cerr << "Invalid course number entry! Enter an integer! (ie. 5) \n"; system("pause"); exit(1); }
	section.setSectionNo(tempSectionNo);

	//GET AND STORE SECTION DAY OF WEEK (CAN BE ANY CALENDAR)
	std::cout << "Enter section day(s) of week: (ie. Tuesday and Thursday)  ";
	std::cin >> tempDayOfWeek;
	section.setDayOfWeek(tempDayOfWeek);

	//GET AND STORE SECTION TIME IF VALID ELSE EXIT
	std::cout << "Enter section time in 24hr format, ie, 1:00pm as \"1300\":  ";
	try { std::cin >> tempTimeOfDay;
		if (std::cin.fail())
			throw "Error: Input does not match required data type!";}
	catch (const char* ex) { std::cerr << "Invalid time! Enter time in 24 hour format! (ie. 1400) \n"; system("pause"); exit(1); }
	section.setTimeOfDay(tempTimeOfDay);

	//GET AND STORE SECTION ROOM
	std::cout << "Enter section room:  (ie. UA2120)  ";
	std::cin >> tempRoom;
	section.setRoom(tempRoom);

	//GET AND STORE SECTION SEATING CAPACITY IF VALID, ELSE EXIT
	std::cout << "Enter room seating capacity: (ie. 240)  ";
	try 
	{
		std::cin >> tempTimeOfDay;
		if (std::cin.fail())
			throw "Error: Input does not match required data type!";
	}
	catch (const char* ex) { std::cerr << "Invalid seating capacity! Enter number of students room can seat! (ie. 200) \n"; system("pause"); exit(1); }
	section.setSeatingCapacity(tempSeatingCapacity);
	return input;
}

//getter definitions
int Section::getSectionNo() const { return sectionNo; }
std::string Section::getDayOfWeek() const { return dayOfWeek; }
int Section::getTimeOfDay() const { return timeOfDay; }
std::string Section::getRoom() const { return room; }
int Section::getSeatingCapacity() const { return seatingCapacity; }
int Section::getSeats() const { return seats; }

//setter definitions
void Section::setSectionNo(int& newSectionNo) { sectionNo = newSectionNo; }
void Section::setDayOfWeek(std::string& newDayOfWeek) { dayOfWeek = newDayOfWeek; }
void Section::setTimeOfDay(int& newTimeOfDay) { timeOfDay = newTimeOfDay; }
void Section::setRoom(std::string& newRoom) { room = newRoom; }
void Section::setSeatingCapacity(int& newSeatingCapacity) { seatingCapacity = newSeatingCapacity; }
void Section::scheduleSection(Course* course,Section& newSection) { newSection; } //creates newSection for a course

//utility definitions
void Section::enroll(Student * student, Section & newSection) //enrolls student in course, adjust seats in section and student courses accordingly 
{ newSection.seats--;
int tempNumberOfCourse = 1 + student->getNumberCourses();
student->setNumberCourses(tempNumberOfCourse); 
} 
void Section::drop(Student* student, Section& newSection) //drops student out of course, adjust seats in section and student courses accordingly 
{
newSection.seats++;
int tempNumberOfCourse = 1 - student->getNumberCourses();
student->setNumberCourses(tempNumberOfCourse); 
} 
bool confirmSeatAvailability(Section& newSection) //return true if seats are avaliable
{
	return (newSection.getSeatingCapacity() - newSection.getSeats() > 0 ? true : false);
}



