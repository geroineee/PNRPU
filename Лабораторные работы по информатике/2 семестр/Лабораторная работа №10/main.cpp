#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
void print(string* a, int n)
{
    cout << "========================" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    cout << "========================" << endl;
}

string* del_maxElement(string* arr, int index, int n) // удаление наибольшего элемента
{
    string* arr2{ new string[n - 1] }; // новый массив меньшей размерности 
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1]; // смещение элементнов относительно удаленного
    }
    for (int i = 0; i < n - 1; i++)
    {
        arr2[i] = arr[i];
    }
    delete[] arr; // очищение памяти старого массива
    return arr2; // возвращаем указатель на новый массив
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    cout << "Введите количество строк: ";
    cin >> n;
    string* arr{ new string[n] }; // динамический массив строк

    for (int i = 0; i < n; i++)
    {
        cin.seekg(cin.eof());
        getline(cin, arr[i]);
    }
    int unsigned maxLen = 0, maxIndex = 0; // длина и индекс наибольшего эелемента
    for (int i = 0; i < n; i++) // нахождение наибольшей строки
    {
        if (arr[i].size() > maxLen)
        {
            maxLen = arr[i].size();
            maxIndex = i;
        }
    }
    cout << "Начальный массив: " << endl;
    print(arr, n);
    cout << "Удалена строка: " << arr[maxIndex] << endl << "========================" << endl;
    arr = del_maxElement(arr, maxIndex, n);
    n--;
    cout << "Новый массив: " << endl;
    print(arr, n);
    return 0;
}
