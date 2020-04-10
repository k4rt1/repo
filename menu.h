#ifndef MENU_H
#define MENU_H
#include "UniversitySystem.h"
using std::cout;

enum ConsoleColor
{
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GRAY = 7,
	COLOR_DARK_GRAY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_YELLOW = 14,
	COLOR_WHITE = 15
};

void run()
{
	ALLOW_RUSSIAN;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((COLOR_BLACK << 4) | COLOR_WHITE));
	
	bool isOpen = true;
	char menuKey;

	University VSU("ÂÃÓ");
	while (isOpen)
	{
		if (!_kbhit())
		{
			system("cls");
			cout << "Ìåíþ:" << endl << "1) Ïðîñìîòð áàçû" << endl << "2) Ðåäàêòèðîâàòü áàçó" << endl << "ESC - âûõîä èç ïðîãðàììû" << endl;
			menuKey = _getch();
			switch (menuKey)
			{
			case '1':
				
				system("cls");
				VSU.printFaculties();
				cout << "" << endl <<"ESC - âåðíóòüñÿ íàçàä" << endl;
				menuKey = _getch();
				
				break;

			case '2':

				break;

			case 27:
				isOpen = false;
				break;
			}

		}
	}



	/*VSU.addFaculty("ÏÌÌ");
	VSU.addSpeciality(VSU.getFaculty("ÏÌÌ"), "ÏÌÈ");
	VSU.addYear(VSU.getSpeciality(VSU.getFaculty("ÏÌÌ"), "ÏÌÈ"), 1);
	VSU.addGroup(VSU.getYear(VSU.getSpeciality(VSU.getFaculty("ÏÌÌ"), "ÏÌÈ"), 1), 4);
	VSU.addStudent("Ãëåá", "Ïåðâååâ", "Îëåãîâè÷", 18, VSU.getFaculty("ÏÌÌ"), VSU.getSpeciality(VSU.getFaculty("ÏÌÌ"), "ÏÌÈ"), VSU.getYear(VSU.getSpeciality(VSU.getFaculty("ÏÌÌ"), "ÏÌÈ"), 1), VSU.getGroup(VSU.getYear(VSU.getSpeciality(VSU.getFaculty("ÏÌÌ"), "ÏÌÈ"), 1), 4));
	VSU.getStudentInfo(VSU.getStudent(VSU.getGroup(VSU.getYear(VSU.getSpeciality(VSU.getFaculty("ÏÌÌ"), "ÏÌÈ"), 1), 4), "Ãëåá", "Ïåðâååâ", "Îëåãîâè÷"));
	*/return;
}

#endif