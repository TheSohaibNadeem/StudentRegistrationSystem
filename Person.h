/*
Author: Sohaib Nadeem
Student Number: 100621437
*/
//ABSTRACT CLASS
#ifndef PERSON_H
#define PERSON_H
#include<string>
#include "Date.h"
class Person
{
public:
	//getters
	virtual std::string getName() const = 0;
	virtual Date getDob() const = 0;
	virtual int getSin() const = 0;

	//setters
	virtual void setName(std::string&) = 0;
	virtual void setDob(Date&) = 0;
	virtual void setSin(long int&) = 0;

private:
	std::string name;
	Date dob;
	long int sin;
};
#endif
