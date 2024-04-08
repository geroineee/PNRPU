#include <iostream>

#include "Person.cpp"

using namespace std;

int main()
{
    // system("chcp 1251>null");
    Person person1("Нашульпанов Денис Васильевич", 35);
    cout << person1;
    Person person2;
    cout << person2;
    Person person3(person1);
    cout << person3;

    Student student1("Виталий Иваанович Наливкин", 20, 0);
    cout << student1;
    student1.setYoS(1);
    cout << student1;
    student1++;
    cout << student1;


    Student student2;
    cout << student2 << endl << endl;
    cin >> student2;

    Student student3;
    student3 = student2;
    cout << student3 << endl;
    return 0;
    cout << student3;
}