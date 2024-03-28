#include <iostream>
#include <chrono>
#include <string>

#include "Boiere_Moore.h"
#include "Binary_search.h"
#include "Interpol_search.h"
#include "Line_search.h"
#include "Line_str_search.h"
#include "KMP.h"
#include "E:\\source\\repos\\TestCpp\\Searches\\output\\HoarSort.h"

using namespace std;



int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(0));
	cout << "Введите размер массива: ";
	int lenght_mas, key;
	cin >> lenght_mas;
	int *mas = new int[lenght_mas];
	for (int i = 0; i < lenght_mas; i++)
	{
		mas[i] = rand() % 101;
		cout << mas[i] << ' ';
	}
	cout << endl;

	cout << "\n-Метод линейного поиска-\n";
	{
		cout << "Какой элемент найти: ";
		cin >> key;
		int found_index = Line_search(mas, key, lenght_mas);
		if (found_index == -1)
		{
			cout << "Элемент не найден" << endl;
		}
		else
		{
			cout << "Номер элемента: " << found_index + 1 << endl;
		}
	}

	ShellSort(mas, lenght_mas);
	cout << "\n-Метод бинарного поиска-\n";
	{
		cout << "Какой элемент найти: ";
		cin >> key;
		int found_index = binary_search(mas, key, lenght_mas);
		if (found_index == -1)
		{
			cout << "Элемент не найден" << endl;
		}
		else
		{
			cout << "Номер элемента: " << found_index + 1 << endl;
		}
	}
	cout << "\n-Метод интерполяционного поиска-\n";
	{
		cout << "Какой элемент найти: ";
		cin >> key;
		int found_index = interpol_search(mas, key, lenght_mas);
		if (found_index == -1)
		{
			cout << "Элемент не найден" << endl;

		}
		else
		{
			cout << "Номер элемента: " << found_index + 1 << endl;

		}
	}

	delete[] mas;

	string str, substr;
	cout << "Введите строку: ";
	cin.seekg(cin.eof());
	getline(cin, str);
	cout << "Введите подстроку: ";
	getline(cin, substr);

	cout << "\n-Метод прямого поиска подстроки в строке-\n";
	{
		int index_str = line_str_search(str, substr);
		if (index_str == -1)
		{
			cout << "Подстрока не найдена" << endl;
		}
		else
		{
			cout << "Номер первого символа подстроки в строке: " << index_str + 1 << endl;
		}
	}
	cout << "\n-Метод Бойера-Мура-\n";
	{
		int shift_table[256];
		table_formation(shift_table, substr);
		int index_str = Boiere_Moore(str, substr, shift_table);
		if (index_str == -1)
		{
			cout << "Подстрока не найдена" << endl;
		}
		else
		{
			cout << "Номер первого символа подстроки в строке: " << index_str + 1 << endl;
		}
	}

	cout << "\n-Метод Кнута/Морриса/Пратта-\n";
	{
		int index_str = KMP_search(str, substr);
		if (index_str == -1)
		{
			cout << "Подстрока не найдена" << endl;
		}
		else
		{
			cout << "Номер первого символа подстроки в строке: " << index_str + 1 << endl;
		}
	}
	return 0;
}