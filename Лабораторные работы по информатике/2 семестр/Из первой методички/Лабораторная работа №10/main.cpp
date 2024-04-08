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

string* del_maxElement(string* arr, int index, int n) // �������� ����������� ��������
{
    string* arr2{ new string[n - 1] }; // ����� ������ ������� ����������� 
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1]; // �������� ���������� ������������ ����������
    }
    for (int i = 0; i < n - 1; i++)
    {
        arr2[i] = arr[i];
    }
    delete[] arr; // �������� ������ ������� �������
    return arr2; // ���������� ��������� �� ����� ������
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    cout << "������� ���������� �����: ";
    cin >> n;
    string* arr{ new string[n] }; // ������������ ������ �����

    for (int i = 0; i < n; i++)
    {
        cin.seekg(cin.eof());
        getline(cin, arr[i]);
    }
    int unsigned maxLen = 0, maxIndex = 0; // ����� � ������ ����������� ���������
    for (int i = 0; i < n; i++) // ���������� ���������� ������
    {
        if (arr[i].size() > maxLen)
        {
            maxLen = arr[i].size();
            maxIndex = i;
        }
    }
    cout << "��������� ������: " << endl;
    print(arr, n);
    cout << "������� ������: " << arr[maxIndex] << endl << "========================" << endl;
    arr = del_maxElement(arr, maxIndex, n);
    n--;
    cout << "����� ������: " << endl;
    print(arr, n);
    return 0;
}
