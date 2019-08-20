/*
Author: Sohaib Nadeem
Student Number: 100621437
*/
#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<vector>

class Course
{
public:
	//constructor
	Course(int = 0, std::string = "", int = 0); //(courseNo, courseName, credits)
	
	//overloaded operators
	friend std::ostream& operator<<(std::ostream&, const Course&); //outputs course information in a formatted manner
	friend std::istream& operator>>(std::istream&, Course&); //prompts user for course information input, stores it in course object aswell as Courses.txt
	
	//getters
	bool hasPrequisite(Course&) const;
	int getCourseNo() const;
	std::string getCourseName() const;
	int getCredits() const;

	//setters
	void addPrerequisite(Course&);
	void setCourseNo(int&);
	void setCourseName(std::string&);
	void setCredits(int&);

private:
	static int courseNo;
	std::string courseName;
	int credits;
	std::vector<Course> preReqs;
};


#endif
