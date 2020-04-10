#ifndef UNIVERSITYSYSTEM_H
#define UNIVERSITYSYSTEM_H

#include "vars.h"

class University
{
private:
	string universityName_;
	uint nStudents_, nFaculties_;
	vector <Faculty> faculties_;

	Faculty* getFaculty(string);
	Speciality* getSpeciality(Faculty*, string);
	Year* getYear(Speciality*, uint);
	Group* getGroup(Year*, uint);
	Student* getStudent(Group*, string, string, string);

public:
	University();
	University(string);
	~University();

	void printFaculties();
	void addStudent(string, string, string, uint, Faculty*, Speciality*, Year*, Group*);
	void addFaculty(string);
	void addSpeciality(Faculty*, string);
	void addYear(Speciality*, uint);
	void addGroup(Year*, uint);
	void getStudentInfo(Student*);
};

#endif