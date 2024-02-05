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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool flag = true;
    int i = 0;
    while (flag && i < n - 1)
    {
        if (a[i] >= a[i + 1])
        {
            flag = false;
            cout << "Последовательность не упорядочена по возрастанию." << endl;
        }
        i++;
    }
    if (flag) cout << "Последовательность упорядочена по возрастанию." << endl;
}
