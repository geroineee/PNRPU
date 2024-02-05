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
    int k;
    cout << endl;
    cout << "Введите k (отрицательный k запускает левостороннее кольцо): " << endl;
    cin >> k;
    if (k > 0) // правостороннее кольцо
    {
        cout << "Вывод кольца с k по k-1 элемент:" << endl;
        k--;
        for (int i = 1; i <= n; i++) //  вывод с k по k-1
        {
            cout << a[k % n] << ' ';
            k++;
        }
    }
    else if (k == 0) cout << "k (номер элемента) не должен быть отрицательным!";
    else // левостороннее кольцо
    {
        cout << "Вывод кольца с k по k+1 элемент:" << endl;
        k++;
        k = abs(k);
        for (int i = 1; i <= n; i++) // вывод с k по k+1
        {
            cout << a[k] << ' ';
            k--;
            if (k < 0) k = n - 1;
        }
    }
    return 0;
}
