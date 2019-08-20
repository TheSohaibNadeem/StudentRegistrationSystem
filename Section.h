/*
Author: Sohaib Nadeem
*/
#ifndef SECTION_H
#define SECTION_H
#include<string>
#include"Course.h"

class Section : public Course
{
public:
	//constructor
	Section(int = 0, std::string = "", int = 0, int = 0, std::string = "", int = 0, std::string = "", int = 0); //(courseNo, courseName, credits, sectionNo, dayOfWeek, timeOfDay, room, seatingCapacity) - Time is in 24 hour format

	//overloaded operators
	friend std::ostream& operator<<(std::ostream&, const Section&);
	friend std::istream& operator>>(std::istream&, Section&);

	//getters
	int getSectionNo() const;
	std::string getDayOfWeek() const;
	int getTimeOfDay() const;
	std::string getRoom() const;
	int getSeatingCapacity() const;
	int getSeats() const; //avaliable seats

	//setters
	void setSectionNo(int&);
	void setDayOfWeek(std::string&);
	void setTimeOfDay(int&);
	void setRoom(std::string&);
	void setSeatingCapacity(int&);
	void scheduleSection(Course*,Section&);
	
	//utility functions
	void enroll(Student*, Section&);
	void drop(Student*, Section&);
	friend bool confirmSeatAvailability(Section&);

private:
	int sectionNo;
	std::string dayOfWeek;
	int timeOfDay;
	std::string room;
	int seatingCapacity;
	int seats;
};
#endif
