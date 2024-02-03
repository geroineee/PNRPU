#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	return sqrt(1 - 0.4 * pow(x, 2)) - asin(x);
}

double derivative_f(double x)
{
	return (-2 * x / (5 * sqrt(1 - 2 * pow(x, 2) / 5))) - (1 / sqrt(1 - pow(x, 2)));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int count = 1;
	const double E = 0.000001;
	double a, b, x0, x;
	bool convex_up, flag = true;
	cout << "Введите отрезок [a;b], на котором есть корень: ";
	cin >> a >> b;
	if (f(a) * f(b) > 0)
		cout << "На этом отрезке нет корня.";
	else if (derivative_f(a) == 0 && derivative_f(b) == 0)
		cout << "Невозможно применить метод Ньютона, производная в некоторой точке на отрезке равну нулю.";
	else
	{
		cout << "Введитe вид графика функции на отрезке [a;b]:" << endl
			 << "1 - если выпуклый вверх" << endl
			 << "0 - если выпуклый вниз" << endl;
		cin >> convex_up;
		if (convex_up && f(a) < 0)
			x0 = a + E;
		else if (convex_up && f(b) < 0)
			x0 = b - E;
		else
		{
			cout << "Ошибка. График не монотонный, либо неверно введен вид графика на отрезке [a;b]";
			flag = false;
		}
		if (flag)
		{
			x = x0 - f(x0) / derivative_f(x0);
			while (abs(x - x0) > E)
			{
				x0 = x;
				x = x0 - f(x0) / derivative_f(x0);
				count++;
			}
			cout << "Примерный корень уравнения: " << x << endl
				 << "Кол-во итераций: " << count;
		}
	}
	return 0;
}
