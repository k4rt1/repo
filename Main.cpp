#include "UniversitySystem.h"\

int main()
{
	AllowRussian;
	University VSU;
	VSU.addFaculty("���");
	VSU.addSpeciality(VSU.getFaculty("���"), "���");
	VSU.addYear(VSU.getSpeciality(VSU.getFaculty("���"), "���"), 1);
	VSU.addGroup(VSU.getYear(VSU.getSpeciality(VSU.getFaculty("���"), "���"), 1), 1);
	VSU.addStudent("����������", "���������", "������������", 20, VSU.getFaculty("���"), VSU.getSpeciality(VSU.getFaculty("���"), "���"), VSU.getYear(VSU.getSpeciality(VSU.getFaculty("���"), "���"), 1), VSU.getGroup(VSU.getYear(VSU.getSpeciality(VSU.getFaculty("���"), "���"), 1), 1));
	VSU.getStudentInfo(VSU.getStudent(VSU.getGroup(VSU.getYear(VSU.getSpeciality(VSU.getFaculty("���"), "���"), 1), 1), "����������", "���������", "������������"));
	return 0;
}
// CONSTTRUCTOR
