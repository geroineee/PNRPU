#include <iostream>
#include <cmath>
using namespace std;
const double E = 0.000001;
int count = 1;

double f(double x)
{
    return sqrt(1 - 0.4 * pow(x, 2)) - asin(x);
}

double fxx(double x)
{
    return sin(sqrt(1 - 0.4 * pow(x, 2)));
}

double derivative_fxx(double x)
{
    return -(2 * x * cos(sqrt(1 - (2 * pow(x, 2)) / 5))) / (5 * sqrt(1 - (2 * pow(x, 2)) / 5));
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double a, b, x, x0;
    cout << "Введите отрезок [a;b], на котором есть корень: ";
    cin >> a >> b;
    if (f(a) * f(b) > 0) cout << "На этом отрезке нет корня.";
    else
    {
        x0 = (a + b) / 2;
        if (abs(derivative_fxx(x0)) < 1)
        {
            x = fxx(x0);
            while (abs(x - x0) > E)
            {
                x0 = x;
                x = fxx(x0);
                count++;
            }
            cout << "Примерный корень уравнения: " << x << endl
                << "Кол-во итераций: " << count;
        }
        else cout << "Метод итераций неприменим к данной функции. Абсолютное значение Производной функции x = f(x) больше 1 в некоторой точке.";
        
    }
    return 0;
}
