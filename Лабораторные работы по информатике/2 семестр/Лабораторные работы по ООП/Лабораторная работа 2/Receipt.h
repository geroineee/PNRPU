#pragma once
#include <string>
#include <iostream>
using namespace std;

class Receipt
{
private:
    int number;
    string date;
    double sum;

public:
    Receipt(int, string, double);
    Receipt();
    ~Receipt();
    Receipt(Receipt &);
    void getInfo();
    void setInfo(int num, string date, double sum);
};

Receipt::Receipt()
{
    cout << "Вызвался стандартный конструктор\n";
    number = 0;
    date = "Unknown data";
    sum = 0;
}

Receipt::Receipt(int num, string date, double sum)
{
    cout << "Вызвался конструктор с параметрами:[number, date, sum]" << " = "
         << "[" << num << ", " << date << ", " << sum << "]\n";
    this->number = num;
    this->date = date;
    this->sum = sum;
}

Receipt::Receipt(Receipt &copying)
{
    cout << "Вызвался конструктор копирования\n";
    this->number = copying.number;
    this->date = copying.date;
    this->sum = copying.sum;
}

Receipt::~Receipt() 
{
    cout << "Вызвался деструктор\n";
}

void Receipt::getInfo()
{
    cout << "Вызвался геттер: [number, date, sum]" << " = "
         << "[" << number << ", " << date << ", " << sum << "]\n";
}

void Receipt::setInfo(int num, string date, double sum)
{
    cout << "Вызвался сеттер с параметрами:[number, date, sum]" << " = "
         << "[" << num << ", " << date << ", " << sum << "]\n";
    this->number = num;
    this->date = date;
    this->sum = sum;
}
