#include <iostream>
#include <chrono> //директива для нахождения времени выполнения части кода
#include <cmath>
using namespace std;

int fact(int n)
{
	n = 2 * n;
	int ans = 1;
	for (int i = 2; i <= n; i++)
	{
		ans *= i;
	}
	return ans;
}

double rek(int n, double x) // рекурсивная функция
{
	if (n == 0)
		return 0;
	return rek(n - 1, x) + (pow(x, 2*n))/fact(n);
}

double ne_rek(int n, double x) // функция для прямого вычисления значения
{
	double summa = 0;
	for (int i = 1; i <= n; i++)
		summa += (pow(x, 2*i))/fact(i);
	return summa;
}

int main()
{
	setlocale(LC_ALL, "RU");
	int n;
	double x;
	cout << "Введите количество членов ряда N: ";
	cin >> n;
	while (n < 0)
	{
		cout << "Введите N > 0: ";
		cin >> n;
	}
	cout << "Введите относительно какого x нужно найти сумму: ";
	cin >> x;
	auto start_rek = chrono::high_resolution_clock::now(); // время, в которое рекурсивная функция начала свою работу
	cout << "Результат через рекурсивную функцию: " << rek(n, x);
	auto end_rek = chrono::high_resolution_clock::now();	// время, в которое рекурсивная функция закончила свою работу
	chrono::duration<float> time_rek = end_rek - start_rek; // находим разницу между этим временем
	cout << ", время: " << time_rek.count() << " сек." << endl;
	auto start_ne_rek = chrono::high_resolution_clock::now(); // начало для не рекурсивной функции
	cout << "Результат через прямое вычисление значения функции: " << ne_rek(n, x);
	auto end_ne_rek = chrono::high_resolution_clock::now();			 // конец для не рекурсивной функции
	chrono::duration<float> time_ne_rek = end_ne_rek - start_ne_rek; // разница
	cout << ", время: " << time_ne_rek.count() << " сек." << endl;
	return 0;
}