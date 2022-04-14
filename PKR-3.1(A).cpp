#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

using namespace std;

enum Specialnist { CS, IT, ME, PhIT, TR };
string specialnistStr[] = { "Computer Science", "Physics", "Mathematics", "Informatics" };

struct Student
{
	string prizv;
	int kurs;
	Specialnist specialnist;
	int physics;
	int math;
	int informatik;
};

void Create(Student* s, int St);
void Print(Student* s, int St);
double GoodMarkSt(Student* s, int St);
double LowSeredBal(Student* s, const int St);

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int St;
	cout << "Number of students: "; cin >> St;
	Student* s = new Student[St];
	Create(s, St);
	Print(s, St);

	cout << "Number of students studying without threes: [" << GoodMarkSt(s, St) << " ];" << endl;
	cout << "Percentage of students with a lower average score of 4: [" << LowSeredBal(s, St) << "%" << " ];" << endl;
	return 0;
}

void Create(Student* s, int St)
{
	int specialnist;
	for (int i = 0; i < St; i++) 
	{
		cout << "Surname: "; 
		cin >> s[i].prizv; 
		cout << "Course: ";
		cin >> s[i].kurs;
		cout << "Specialty (0 - Computer Science; 1 - Physics; 2 - Mathematics; 3 - Informatics;) :" << endl;
		cin >> specialnist;
		s[i].specialnist = (Specialnist)specialnist;
		cout << "Physics grade: "; 
		cin >> s[i].physics; 
		cout << "Mathematics grade: "; 
		cin >> s[i].math; 
		cout << "Informatics grade: "; 
		cin >> s[i].informatik; 
	}
}

void Print(Student* s, int St)
{
	cout << "========================================================================="
		<< endl;
	cout << "| № | Surname | Course | Specialty | Physic | Mathematic | Informatic |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < St; i++) {

		cout << "|" << setw(3) << right << i + 1 << "  ";
		cout << "| " << setw(3) << right << s[i].kurs << "  "
			<< "|" << setw(16) << left << s[i].prizv
			<< "| " << setw(24) << left << specialnistStr[s[i].specialnist]
			<< "| " << setw(3) << right << s[i].physics << "    "
			<< "| " << setw(6) << right << s[i].math << "     "
			<< "| " << setw(6) << right << s[i].informatik << "    " << "| ";
		cout << endl;
	}
	cout << "-------------------------------------------------------------------------------------------"
		<< endl;
}

double GoodMarkSt(Student* s, int St)
{
	int k = 0;
	for (int i = 0; i < St; i++)
	{
		if (s[i].physics == 5 || s[i].physics == 4) 
		{
		    if (s[i].math == 5 || s[i].math == 4)
		    {
			    if (s[i].informatik == 5 || s[i].informatik == 4)
			    {
				    k++;
				}
		    }
		}
	}
	return k;
}

double LowSeredBal(Student* s, const int St)
{
	int k = 0;
	for (int i = 0; i < St; i++)
	{
		if (s[i].physics < 4)
		{
			if (s[i].math < 4)
			{
				if (s[i].informatik < 4)
				{
					k++;
				}
			}
		}
	}
	return 100.0 * k / St;
}
