/*
Author: Sohaib Nadeem
Student Number: 100621437
*/
//This class allows the user flexibility in setting dates, there are no hard limits so the user is not limited to any particular calendar
#ifndef DATE_H
#define DATE_H
#include<iostream>
class Date
{
public:
	Date(int = 1, int = 1, int = 1); //constructor (day, month, year)
										//getter functions
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	//overloaded operators
	bool operator == (Date const); //returns true if two objects of type date are equal , else returns false
	friend std::ostream& operator<<(std::ostream&, Date& const);
	friend std::istream& operator>>(std::istream&, Date&);

private:
	int day;
	int month;
	int year;
};
#endif
