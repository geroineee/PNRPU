#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RU");
    int a[100], n;
    cout << "Введите размер массива: " << endl;
    cin >> n;
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < n; i++) // ввод элементов
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) // проход по элементам массива
    {
        if (a[i] % 2 == 0)
        {
            n += 1;
            for (int j = n; j > i; j--) a[j] = a[j-1]; // сдвиг элементов
            a[i] = -1;
            i++;
        }
    }
    for (int i = 0; i < n; i++) // вывод массива
        cout << a[i] << ' ';
}
