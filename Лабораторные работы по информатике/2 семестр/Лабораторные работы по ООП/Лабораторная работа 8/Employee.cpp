#pragma once

#include "Classes.h"

Employee::Employee() : Person()
{
	this->salary = 0;
	this->post = "";
}

Employee::Employee(string name, int age, float salary, string post) : Person(name, age)
{
	this->age = age;
	this->post = post;
}

Employee::Employee(const Employee &other_employee)
{
	this->age = other_employee.age;
	this->Name = other_employee.Name;
	this->salary = other_employee.salary;
}

void Employee::Show(bool names = false)
{
	if (!names)
	{
		cout << "\nИмя: " << this->Name << " Возраст: " << this->age
			 << "\nЗарплата: " << this->salary << " Должность: " << this->post << "\n\n";
	}
	else
	{
		cout << "\nИмя: " << this->Name << "\n\n";
	}
}

void Employee::Input()
{
	cout << "\nВведите данные работника:\n";
	cout << "Название: ";
	cin.seekg(cin.eof());
	getline(cin, this->Name);
	cout << "Возраст: ";
	cin >> this->age;
	cout << "Зарплата: ";
	cin >> this->salary;
	cout << "Должность: ";
	cin.seekg(cin.eof());
	getline(cin, this->post);

}

Employee &Employee::operator=(const Employee &other_employee)
{
	if (this == &other_employee)
	{
		return *this;
	}
	Person::operator=(other_employee);
	this->salary = other_employee.salary;
	this->post = other_employee.post;
	return *this;
}