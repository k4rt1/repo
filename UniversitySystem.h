#pragma once

#include "vars.h"

class University
{
private:
	string nameOfUniversity;
	uint numberOfAllStudents, numberOfFaculties;
	vector <Faculty> faculties;

public:
	University();
	University(string);
	~University();

	Faculty* getFaculty(string);
	Speciality* getSpeciality(Faculty*, string);
	Year* getYear(Speciality*, uint);
	Group* getGroup(Year*, uint);
	Student* getStudent(Group*, string, string, string);

	void addStudent(string, string, string, uint, Faculty*, Speciality*, Year*, Group*);
	void addFaculty(string);
	void addSpeciality(Faculty*, string);
	void addYear(Speciality*, uint);
	void addGroup(Year*, uint);
	void getStudentInfo(Student*);

};