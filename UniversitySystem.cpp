#include "UniversitySystem.h"

//-----------------------

University::University()
{
	universityName_ = "Unnamed";
	nStudents_ = 0;
	nFaculties_ = 0;
};
University::University(string name)
{
	universityName_ = name;
	nStudents_ = 0;
	nFaculties_ = 0;
}
University::~University()
{
};

//-----------------------

void
University::addFaculty(string newFacultyName)
{
	for(size_t i = 0; i < faculties_.size();i++)
		if (faculties_[i].facultyName == newFacultyName)
		{
			cout << "Факультет с названием " << '"' << newFacultyName << '"' << " уже существует.";
			break;
		}
	Faculty newFaculty;
	newFaculty.facultyName = newFacultyName;
	faculties_.push_back(newFaculty);
	nFaculties_++;

	return;
};

void
University::addSpeciality(Faculty* faculty, string newSpecialityName)
{
	Speciality newSpeciality;
	newSpeciality.specialityName = newSpecialityName;
	newSpeciality.faculty = faculty;
	faculty->specialities.push_back(newSpeciality);
	faculty->nSpecialities++;

	return;
}

void
University::addYear(Speciality* speciality, uint year)
{
	Year newYear;
	newYear.yearNo = year;
	newYear.speciality = speciality;
	speciality->years.push_back(newYear);
	speciality->nYears++;

	return;
}

void
University::addGroup(Year* year, uint number)
{
	Group newGroup;
	newGroup.groupNo = number;
	newGroup.year = year;
	year->groups.push_back(newGroup);
	year->nGroups++;

	return;
};

void
University::addStudent(string name, string surname, string patronym, uint age, Faculty* faculty, Speciality* speciality, Year* year, Group* group)
{
	Student newStudent;
	newStudent.age = age;
	newStudent.name = name;
	newStudent.patronym = patronym;
	newStudent.surname = surname;
	newStudent.group = group;
	group->students.push_back(newStudent);
	group->nGroupStudents++;
	year->nYearStudents++;
	speciality->nSpecialityStudents++;
	faculty->nFacultyStudents++;
	nStudents_++;

	return;
};

void
University::getStudentInfo(Student* student)
{
	cout << "Фамилия: " << student->surname << endl;
	cout << "Имя: " << student->name << endl;
	cout << "Отчество: " << student->patronym << endl;
	cout << "Возраст: " << student->age << endl;
	cout << "Вуз: " << universityName_ << endl;
	cout << "Факультет: " << student->group->year->speciality->faculty->facultyName << endl;
	cout << "Направление: " << student->group->year->speciality->specialityName << endl;
	cout << "Курс: " << student->group->year->yearNo << endl;
	cout << "Группа: " << student->group->groupNo << endl;

	return;
};

void
University::printFaculties()
{
	if (faculties_.size())
	{
		for (size_t i = 0; i < faculties_.size(); i++)
			cout << i + 1 << ") " << faculties_[i].facultyName;
	}
	else
	{
		cout << "Факультеты ещё не добавлены." << endl;
	}

	return;
}

//-----------------------

Faculty*
University::getFaculty(string newFacultyName)
{
	for (uint i = 0; i < nFaculties_; i++)
		if (newFacultyName == faculties_[i].facultyName)
			return &faculties_[i];
	return nullptr;
}

Speciality*
University::getSpeciality(Faculty* faculty, string newSpecialityName)
{
	for (uint i = 0; i < faculty->nSpecialities; i++)
		if (newSpecialityName == faculty->specialities[i].specialityName)
			return &faculty->specialities[i];
	return nullptr;
}

Year*
University::getYear(Speciality* speciality, uint number)
{
	for (uint i = 0; i < speciality->nYears; i++)
		if (number == speciality->years[i].yearNo)
			return &speciality->years[i];
	return nullptr;
};

Group*
University::getGroup(Year* year, uint number)
{
	for (uint i = 0; i < year->nGroups; i++)
		if (number == year->groups[i].groupNo)
			return &year->groups[i];
	return nullptr;
};

Student*
University::getStudent(Group* group, string name, string surname, string patronym)
{
	for (uint i = 0; i < group->nGroupStudents; i++)
		if (name == group->students[i].name && surname == group->students[i].surname && patronym == group->students[i].patronym)
			return &group->students[i];
	return nullptr;
}
