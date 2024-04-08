#include <iostream>
#include <clocale>
using namespace std;
void Hanoi (int n, int start,int finish)
{
    int temp;
    if (n == 1)
    {
        cout << start << " => " << finish << endl;
    }
    else
    {
        temp = 6 - start - finish;
        Hanoi(n - 1, start, temp);
        cout << start << " => " << finish << endl;
        Hanoi(n - 1, temp, finish);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << " Введите колличество дисков: ";
    cin >> n;
    Hanoi(n, 1, 3);
    return 0;
}

