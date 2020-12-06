#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;
struct Student
{
	string prizv;
	unsigned kurs;
	unsigned fiz;
	unsigned mat;
	unsigned inf;

};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double LineSearch(Student* p, const int N);
void Sort(Student* p, const int N);
int main()
{ // ������������ ����������� ��������:
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
	int N;
	cout << "������ N: ";
	cin >> N;
	double proc;

	Student* p = new Student[N];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ���� �������� ��� ������ ����� 3" << endl;
		cout << " [4] - ������� ������������� �����" << endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			proc = LineSearch(p, N);
			cout << "ʳ������ �������� ��� ������ ����� 3:" << endl;
			cout << proc << "%" << endl;
			break;
		case 4:
			Sort(p, N);
			break;
			cout << Sort << endl;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int posada;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������ � ������: ";
		cin >> p[i].fiz;
		cout << " ������ � ����������: "; cin >> p[i].mat;
		cout << " ������ � �����������: "; cin >> p[i].inf;
		switch (p[i].fiz)
			cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "==========================================================================="
		<< endl;
	cout << "| � | ������� | ���� | ������������ | Գ���� | ���������� | ����������� |"
		<< endl;
	cout << "---------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(8) << left << p[i].prizv;
		cout << "| " << setw(10) << right << p[i].kurs << " ";
		cout << "| " << setw(10) << right << p[i].fiz << " ";
		cout << "| " << setw(10) << right << p[i].mat << " ";
		cout << "| " << setw(10) << right << p[i].inf << " ";
		cout << endl;
	}

	cout << "========================================================================="
		<< endl;
	cout << endl;
}
double LineSearch(Student* p, const int N)
{
	cout << "������� ��������, ��� ������ ����� 3:" << endl;
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].fiz == p[i + 1].fiz)
		{
			n++;
			if (p[i].fiz > 3)
			{
				k++;
				cout << setw(3) << right << k
					<< " " << p[i].prizv << endl;
			}
		}
	}
	return 100 * k / n;
}
void Sort(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].fiz > p[i1 + 1].fiz)
				||
				(p[i1].fiz == p[i1 + 1].fiz &&
					p[i1].prizv > p[i1 + 1].prizv))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}