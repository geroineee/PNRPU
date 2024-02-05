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
    int max_index = 0, cnt = 1;
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << endl;
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            max_index = i;
            cnt = 1;
        }
        else if (a[i] == max)
            cnt += 1;
    }
    cout << "Максимальное число: " << max << ", его индекс: " << max_index + 1 << ", количество максимумов: " << cnt;
}
