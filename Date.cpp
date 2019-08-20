/*
Author: Sohaib Nadeem
Student Number: 100621437
*/
#include "Date.h"

//constructor definition
Date::Date(int newDay, int newMonth, int newYear) :day(newDay), month(newMonth), year(newYear) {}//constructor defintion

//getter definitions
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

//overloaded operator definitions
bool Date::operator==(Date dateTwo)
{
	if (getDay() == dateTwo.getDay() && getMonth() == dateTwo.getMonth() && getYear() == dateTwo.getYear())
	{
		return true;
	}
	else
		return false;
}
std::ostream& operator<<(std::ostream& out, Date& date) //Outputs date in format :: M/D/Y
{
	out << date.getMonth() << "/" << date.getDay() << "/" << date.getYear();
	return out;
}

std::istream& operator>>(std::istream& input, Date& Date) //Takes consecutive inputs to modify a date object in order month, day, year
{
	input >> Date.month >> Date.day >> Date.year;
	return input;
}
