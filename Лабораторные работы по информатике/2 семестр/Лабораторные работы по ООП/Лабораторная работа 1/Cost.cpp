#pragma once
#include "Cost.h"


Dialog::Dialog(unsigned int first, double second)
{
    cout << "Вызов конструктора класса Dialog\n";
	first = first;
	second = second;
}

void Dialog::cost()
{
	cout << "Общая сумма разговора: " << first*second << endl;
}

void Dialog::setFirst(unsigned int a0)
{
	cout << "Количество минут разговора = " << a0 << endl;
	first = a0;
}

void Dialog::setSecond(double r)
{
	cout << "Стоимость одной минуты разговора = " << r << endl;
	second = r;
}
