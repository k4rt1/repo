#ifndef VARS_H
#define VARS_H

#define AllowRussian SetConsoleCP(1251); \
 SetConsoleOutputCP(1251);
typedef unsigned int uint;

#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>


using std::string;
using std::vector;
using std::cout;
using std::endl;

struct Student
{
	string name, surname, patronym;
	uint age = 0;
	struct Group* group = nullptr;
};
struct Group
{
	uint numberOfGroup = 0, numberOfGroupStudents = 0;
	vector <Student> students;
	struct Year* year = nullptr;
};
struct Year
{
	uint numberOfYear = 0, numberOfYearStudents = 0, numberOfGroups = 0;
	vector <Group> groups;
	struct Speciality* speciality = nullptr;
};

struct Speciality
{
	string specialityName;
	uint numberOfSpecialityStudents = 0, numberOfYears = 0;
	vector <Year> years;
	struct Faculty* faculty = nullptr;
};
struct Faculty
{
	string facultyName;
	uint numberOfFacultyStudents = 0, numberOfSpecialities = 0;
	vector <Speciality> specialities;
};


#endif