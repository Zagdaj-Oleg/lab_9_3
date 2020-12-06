#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
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
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	int N;
	cout << "Введіть N: ";
	cin >> N;
	double proc;

	Student* p = new Student[N];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - вивід студентів чия оцінка більша 3" << endl;
		cout << " [4] - фізичне впорядкування даних" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
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
			cout << "Кількість студентів чия оцінка більша 3:" << endl;
			cout << proc << "%" << endl;
			break;
		case 4:
			Sort(p, N);
			break;
			cout << Sort << endl;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int posada;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].kurs;
		cout << " оцінка з фізики: ";
		cin >> p[i].fiz;
		cout << " оцінка з математики: "; cin >> p[i].mat;
		cout << " оцінка з інформатики: "; cin >> p[i].inf;
		switch (p[i].fiz)
			cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "==========================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Інформатика |"
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
	cout << "Прізвища студентів, чия оцінка більша 3:" << endl;
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
	for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
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