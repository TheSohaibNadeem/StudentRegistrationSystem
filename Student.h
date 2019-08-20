/*
Author: Sohaib Nadeem
Student Number: 100621437
*/
#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student : public Person
{
public:
	//constructor
	Student(std::string = "No Name", Date = (-1,-1,-1), int = -1, std::string = "No Major", int = 0, std::string = "No Department", bool = false); //(name, dob, sin, major, numberCourses, department, agreeToTeach)
	
	//overloaded operators
	friend std::ostream& operator<<(std::ostream&, const Student&); //outputs formatted Student info 
	friend std::istream& operator>>(std::istream&, Student&); //prompts user for student info and stores it in the student object and Students.txt file

	//getters
	std::string getMajor() const;
	std::string getDepartment() const;
	int getNumberCourses() const;
	int getAgreeToTeach() const;
	friend int getStudentNo();
	std::string getName() const;
	Date getDob() const;
	int getSin() const;


	//setters
	void setMajor(std::string&);
	void setDepartment(std::string&);
	void setNumberCourses(int&);
	void setAgreeToTeach(bool&);
	void setName(std::string&);
	void setDob(Date&);
	void setSin(long int&);

	//counter
	static int studentNo; //to track number of students registered (not number of student objects)

private:
	std::string name;
	Date dob;
	int sin;
	std::string major;
	std::string department;
	int numberCourses;
	bool agreeToTeach;	
};
#endif
