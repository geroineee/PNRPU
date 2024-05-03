#include <iostream>
#include <fstream>

#include "Pair.h"
#include "Pair.cpp"
#include "file_work.h"

using namespace std;

int main() 
{
	// system("chcp 1251 > Null");
	srand(time(0));
	int N;
	do
	{
		cout << "Введите кол-во элементов: ";
		cin >> N;
	} while (N < 1);

	cout << "\n";

	write_to_a_file(N);

	bool isRunning = true;
	while (isRunning) 
	{
		int current_action = choosing_an_action();
		int tmp_int;
		double tmp_double;

		Pair pair;
		switch (current_action) 
		{
		case 1:
			cout << "Текущее содержимое файла:\n";
			print_file();
			cout << endl;
			break;
		case 2:
			do 
			{
				cout << "Введите кол-во элементов: ";
				cin >> tmp_int;
			} while (tmp_int < 1);
			write_to_a_file(tmp_int);
			break;
		case 3:
			cout << "Введите минимальное значение пары (int double):\n";
			cin >> pair;
			removing_el_smaller_than(pair);
			break;
		case 4:
			do 
			{
				cout << "Какое число вы хотите ввести?\n";
				cout << "1 - целое \n2 - вещественное\n";
				cin >> N;
			} while (N < 1 || N>2);
			switch (N) 
			{
			case 1:
				cout << "Введите ЦЕЛОЕ число: ";
				cin >> tmp_int;
				add_L(tmp_int);
				break;
			default:
				cout << "Введите ВЕЩЕСТВЕННОЕ число: ";
				cin >> tmp_double;
				add_L(tmp_double);
				break;
			}
			break;
		case 5:
			do 
			{
				cout << "Введите НОМЕР, после которого необходимо ввести k элементов\n";
				cin >> N;
			} while (N < 1);

			do 
			{
				cout << "Введите количество элементов, которые необходимо добавить\n";
				cin >> tmp_int;
			} while (tmp_int < 1);
			add_k_el_after(N, tmp_int);
			break;
		default:
			isRunning = false;
			break;
		}
	}
	return 0;
}