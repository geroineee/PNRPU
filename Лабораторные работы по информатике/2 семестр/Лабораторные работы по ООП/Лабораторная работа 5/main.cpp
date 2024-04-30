#include <iostream>
#include <vector>

#include "Object.h"
#include "Object.cpp"

using namespace std;

int main()
{
    vector<Object *> vect;
    Person person;
    Student student;
    cout << "Инициализация обьекта класса Person:\n";
    cin >> person;
    cout << "Введенные данные:\n";
    cout << person;
    cout << "Инициализация обьекта класса Student:\n";
    cin >> student;
    cout << "Введенные данные:\n";
    cout << student;
    vect.push_back(&person);
    vect.push_back(&student);
    cout << endl
         << endl;
    for (int i = 0; i < int(vect.size()); i++)
    {
        vect[i]->output();
    }
}