#pragma once
#include <iostream>

class Pair
{
private:
    int first;
    double second;

public:
    Pair();
    Pair(int, double);
    Pair(Pair &);
    //~Pair();

    bool operator<(Pair &);
    bool operator>(Pair &);
    Pair &operator++();
    Pair &operator++(int);
    friend std::ostream &operator<<(std::ostream &out, Pair i);

    void get();
    void set(int, double);
};

Pair::Pair()
{
    this->first = 0;
    this->second = 0;
}

Pair::Pair(int fir, double sec)
{
    this->first = fir;
    this->second = sec;
}

Pair::Pair(Pair &copying)
{
    this->first = copying.first;
    this->second = copying.second;
}

// Pair::~Pair() {}

bool Pair::operator<(Pair &temp)
{
    if ((this->first + this->second) < (temp.first + temp.second))
        return true;
    return false;
}

bool Pair::operator>(Pair &temp)
{
    if ((this->first + this->second) > (temp.first + temp.second))
        return true;
    return false;
}

Pair &Pair::operator++()
{
    ++this->first;
    return *this;
}

Pair &Pair::operator++(int)
{
    ++this->second;
    return *this;
}

void Pair::get()
{
    std::cout << this->first << ':' << this->second;
}

void Pair::set(int fir, double sec)
{
    this->first = fir;
    this->second = sec;
}

std::ostream &operator<<(std::ostream &pairout, Pair temp)
{
    return (pairout << temp.first << ':' << temp.second);
}