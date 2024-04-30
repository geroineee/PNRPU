#include <iostream>
#include <string>

using namespace std;

Student &Student::operator++()
{
    ++this->year_of_study;
    return *this;
}

Student &Student::operator++(int)
{
    this->year_of_study++;
    return *this;
}

Person::Person()
{
    cout << "Вызвался конструктор без параметров для объекта " << this << endl;
    this->name = "-";
    this->age = 0;
}

Person::Person(string name, int age)
{
    cout << "Вызвался конструктор с параметрами для объекта " << this << endl;
    this->name = name;
    this->age = age;
}

Person::Person(const Person &other)
{
    cout << "Вызвался конструктор копирования для объекта " << this << endl;
    this->name = other.name;
    this->age = other.age;
}

Person::~Person()
{
    cout << "Вызвался деструктор для объекта " << this << endl;
}

void Person::operator=(const Person &person)
{
    this->name = person.name;
    this->age = person.age;
}

ostream &operator<<(ostream &stream, Person &person)
{
    stream << "ФИО: " << person.name << endl
           << "Возраст: " << person.age << "\n\n";
    return stream;
}

istream &operator>>(istream &stream, Person &person)
{
    string name;
    int age;
    cout << "Введите имя: ";
    cin.seekg(cin.eof());
    getline(cin, name);
    cout << "Введите возраст: ";
    cin >> age;
    person.setName(name);
    person.setAge(age);
    return stream;
}

Student::Student()
{
    this->name = "-";
    this->age = 0;
    this->year_of_study = 0;
}

Student::Student(string name, int age, int yos)
{
    this->name = name;
    this->age = age;
    this->year_of_study = yos;
}

void Student::setYoS(int yos)
{
    this->year_of_study = yos;
}

ostream &operator<<(ostream &stream, const Student &student)
{
    stream << "Имя: " << student.name << endl
           << "Возраст: " << student.age << endl
           << "Год обучения: " << student.year_of_study << endl
           << endl;
    return stream;
}

istream &operator>>(istream &stream, Student &student)
{

    string name;
    int yos, age;
    cout << "Введите ФИО: ";
    cin.seekg(cin.eof());
    getline(stream, student.name);
    cout << "Введите возраст: ";
    stream >> age;
    student.age = age;
    cout << "Введите год обучения: ";
    stream >> yos;
    student.setYoS(yos);
    return stream;
}

void Student::setName(const string name)
{
    this->Person::name = name;
}

void Student::setAge(const int age)
{
    this->Person::age = age;
}

void Person::setName(const string name)
{
    this->name = name;
}

void Person::setAge(const int age)
{
    this->age = age;
}

void Person::output()
{
    cout << "\tДанные о человеке:\nФИО: " << this->name << endl
         << "Возраст: " << this->age << "\n\n";
}

void Student::output()
{
    cout << "\tДанные о студенте:\nФИО: " << this->name << endl
         << "Возраст: " << this->age << endl
         << "Год обучения: " << this->year_of_study << "\n\n";
}

string Person::getName()
{
    return this->name;
}

int Person::getAge()
{
    return this->age;
}

string Student::getName()
{
    return this->name;
}

int Student::getAge()
{
    return this->age;
}