#include "UniversitySystem.h"\

int main()
{
	AllowRussian;
	University VSU;
	VSU.addFaculty("ПММ");
	VSU.addSpeciality(VSU.getFaculty("ПММ"), "ПМИ");
	VSU.addYear(VSU.getSpeciality(VSU.getFaculty("ПММ"), "ПМИ"), 1);
	VSU.addGroup(VSU.getYear(VSU.getSpeciality(VSU.getFaculty("ПММ"), "ПМИ"), 1), 1);
	VSU.addStudent("Александра", "Кончакова", "Владимировна", 20, VSU.getFaculty("ПММ"), VSU.getSpeciality(VSU.getFaculty("ПММ"), "ПМИ"), VSU.getYear(VSU.getSpeciality(VSU.getFaculty("ПММ"), "ПМИ"), 1), VSU.getGroup(VSU.getYear(VSU.getSpeciality(VSU.getFaculty("ПММ"), "ПМИ"), 1), 1));
	VSU.getStudentInfo(VSU.getStudent(VSU.getGroup(VSU.getYear(VSU.getSpeciality(VSU.getFaculty("ПММ"), "ПМИ"), 1), 1), "Александра", "Кончакова", "Владимировна"));
	return 0;
}
// CONSTTRUCTOR
