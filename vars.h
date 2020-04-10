#ifndef VARS_H
#define VARS_H

#define ALLOW_RUSSIAN SetConsoleCP(1251); \
 SetConsoleOutputCP(1251);
typedef unsigned int uint;

#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <conio.h>

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
	uint groupNo = 0, nGroupStudents = 0;
	vector <Student> students;
	struct Year* year = nullptr;
};

struct Year
{
	uint yearNo = 0, nYearStudents = 0, nGroups = 0;
	vector <Group> groups;
	struct Speciality* speciality = nullptr;
};

struct Speciality
{
	string specialityName;
	uint nSpecialityStudents = 0, nYears = 0;
	vector <Year> years;
	struct Faculty* faculty = nullptr;
};

struct Faculty
{
	string facultyName;
	uint nFacultyStudents = 0, nSpecialities = 0;
	vector <Speciality> specialities;
};

#endif