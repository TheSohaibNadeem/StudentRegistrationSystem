/*
Author: Sohaib Nadeem
Student Number: 100621437
*/
#ifndef PROFESSOR_H
#define PROFESSOR_H
#include"Person.h"

class Professor : public Person
{
public:
	//Constructor
	Professor(std::string = "No name" , Date = (0,0,0) , int = -1, std::string = "No Office", int = 0, std::string="No Status"); //(name, dob, sin, office, numberOfCourses, employment status)
	
	//overloaded operators
	friend std::ostream& operator<<(std::ostream&, const Professor&);
	friend std::istream& operator>>(std::istream&, Professor&);
																										
	//getters
	std::string getOffice() const;
	int getNumberOfCourses() const;
	std::string getEmploymentStatus() const;
	std::string getName() const;
	Date getDob() const;
	int getSin() const;


	
	
	//setters
	void setOffice(std::string&);
	void setNumberOfCourses(int&);
	void setEmplyomentStatus(std::string&);
	void setName(std::string&);
	void setDob(Date&);
	void setSin(int&);
private:
	std::string name;
	Date dob;
	int sin;
	std::string office;
	int numberOfCourses;
	std::string employmentStatus;
};
#endif