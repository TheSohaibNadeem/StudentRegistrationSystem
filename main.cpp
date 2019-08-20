/*
Author: Sohaib Nadeem
Student Number: 100621437
*/
#include<fstream>
#include<iostream>
#include<cstdlib>
#include"Course.h"
#include"Person.h"
#include"Date.h"
#include"Professor.h"
#include "Student.h"

std::string cleanString(std::string inputStr); //function filters user input of .'s, ,'s and " "'s

int main()
{
	Course blankCourseObject;
	Student blankStudentObject;
	std::string testInput;
	
	std::cout << "REMINDER: Leave program running! Closing and restarting the program requires clearing ALL students!"; //warning to user

	//Program lifetime loop
	while (true) {
		std::cout << "Press ENTER to continue: ";
		std::cin.ignore();
		int input;
		std::cout << "\nPlease enter what you would like to do: \n1. Add New Student\n2. Add New Course\n3. Display Courses \n4. Display Students\n";
		std::cin >> testInput;
		input = std::atoi(cleanString(testInput).c_str()); //removes " "'s, ,'s and .'s from input and converts to datatype int

		try //handle out of range/invalid input
		{
			if (input != 1 && input != 2 && input != 3 && input != 4)
				throw input;
		}
		catch (int ex)
		{
			std::cout << "You have not entered a a valid option. Please enter either 1, 2, 3, or 4.";
		}

		//ADD NEW STUDENT (1)
		if (input == 1)
		{
			std::cin >> blankStudentObject;
			Student::studentNo++;
			std::cout << "Total number of students in System: " << getStudentNo() << std::endl;
		}
		
		//ADD COURSE (2)
		if (input == 2)
		{
			std::cin >> blankCourseObject;
		}

		//DISPLAY COURSES (3)
		if (input == 3)
		{
			std::ifstream courseFileIn("Courses.txt");
			if (courseFileIn.is_open())
				std::cout << courseFileIn.rdbuf();
			else
			{
				std::cerr << "Error reading course file. Please delete Students.txt and re-run program.";
				system("pause");
				exit(1);
			}
		}
		//DISPLAY STUDENTS (4)
		if (input == 4)
		{
			std::ifstream studentFileIn("Students.txt");
			if (studentFileIn.is_open())
			{
				std::cout << studentFileIn.rdbuf();
				std::cout << "Total number of students in System: " << getStudentNo() << std::endl;
				studentFileIn.close();
			}
			else
			{
				std::cerr << "Error reading student file. Please delete Students.txt and re-run program.";
				system("pause");
				exit(1);
			}
		}
		std::cin.ignore();
	}
	system("pause");
	return 0;
}
//String cleaner function, removes . " " and ,'s
std::string cleanString(std::string inputStr) {
	std::string cleanString = "";
	int length = inputStr.length();
	for (int i = 0; i < length; i++) {
		char currentChar = inputStr.at(i);
		if (currentChar != '.' && currentChar!=' ' && currentChar!=',') {

			cleanString += currentChar;
		}
	}
	return cleanString;
}