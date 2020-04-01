#include "UniversitySystem.h"

University::University()
{
	nameOfUniversity = "ВГУ";
	numberOfAllStudents = 0;
	numberOfFaculties = 0;
};
University::University(string name)
{
	nameOfUniversity = name;
	numberOfAllStudents = 0;
	numberOfFaculties = 0;
}
University::~University()
{
};

// ADD
void University::addFaculty(string newFacultyName)
{
	Faculty newFaculty;
	newFaculty.facultyName = newFacultyName;
	faculties.push_back(newFaculty);
	numberOfFaculties++;

	return;
};  // добавить проверку на уикальность

void University::addSpeciality(Faculty* faculty, string newSpecialityName)
{
	Speciality newSpeciality;
	newSpeciality.specialityName = newSpecialityName;
	newSpeciality.faculty = faculty;
	faculty->specialities.push_back(newSpeciality);
	faculty->numberOfSpecialities++;

	return;
}
void University::addYear(Speciality* speciality, uint year)
{
	Year newYear;
	newYear.numberOfYear = year;
	newYear.speciality = speciality;
	speciality->years.push_back(newYear);
	speciality->numberOfYears++;

	return;
} // добавить проверку на уикальность
void University::addGroup(Year* year, uint number)
{
	Group newGroup;
	newGroup.numberOfGroup = number;
	newGroup.year = year;
	year->groups.push_back(newGroup);
	year->numberOfGroups++;

	return;
}; // добавить проверку на уикальность
void University::addStudent(string name, string surname, string patronym, uint age, Faculty* faculty, Speciality* speciality, Year* year, Group* group)
{
	Student newStudent;
	newStudent.age = age;
	newStudent.name = name;
	newStudent.patronym = patronym;
	newStudent.surname = surname;
	newStudent.group = group;
	group->students.push_back(newStudent);
	group->numberOfGroupStudents++;
	year->numberOfYearStudents++;
	speciality->numberOfSpecialityStudents++;
	faculty->numberOfFacultyStudents++;
	numberOfAllStudents++;

	return;
};  // добавить проверку на уикальность

// GET
Faculty* University::getFaculty(string newFacultyName)
{
	for (uint i = 0; i < numberOfFaculties; i++)
		if (newFacultyName == faculties[i].facultyName)
			return &faculties[i];
	return nullptr;
}
Speciality* University::getSpeciality(Faculty* faculty, string newSpecialityName)
{
	for (uint i = 0; i < faculty->numberOfSpecialities; i++)
		if (newSpecialityName == faculty->specialities[i].specialityName)
			return &faculty->specialities[i];
	return nullptr;
}
Year* University::getYear(Speciality* speciality, uint number)
{
	for (uint i = 0; i < speciality->numberOfYears; i++)
		if (number == speciality->years[i].numberOfYear)
			return &speciality->years[i];
	return nullptr;
};
Group* University::getGroup(Year* year, uint number)
{
	for (uint i = 0; i < year->numberOfGroups; i++)
		if (number == year->groups[i].numberOfGroup)
			return &year->groups[i];
	return nullptr;
};
Student* University::getStudent(Group* group, string name, string surname, string patronym)
{
	for (uint i = 0; i < group->numberOfGroupStudents; i++)
		if (name == group->students[i].name && surname == group->students[i].surname && patronym == group->students[i].patronym)
			return &group->students[i];
	return nullptr;
}
void University::getStudentInfo(Student* student)
{
	cout << "Имя: " << student->name << endl << "Фамилия: " << student->surname << endl;
	cout << "Отчество: " << student->patronym << endl << "Вуз: " << nameOfUniversity << endl;
	cout << "Факультет: " << student->group->year->speciality->faculty->facultyName << endl;
	cout << "Направление: " << student->group->year->speciality->specialityName << endl;
	cout << "Курс: " << student->group->year->numberOfYear << endl;
	cout << "Группа: " << student->group->numberOfGroup << endl;

	return;
};