#pragma once
#include <iostream> 
using namespace std;

class Pair
{
private:
	int first;
	double second;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair() {}
	void Print();

	Pair operator+(const Pair&);
	Pair operator-(const Pair&);
	void setFirst(const int&);
	void setSecond(const double&);
	int getFirst();
	double getSecond();
	void operator=(const Pair&);
	friend ostream& operator <<(ostream&, const Pair&);
	friend istream& operator >>(istream&, Pair&);
	bool operator >(const Pair&);
	bool operator <(const Pair&);
	friend bool operator==(const Pair&, const Pair&);
	void operator/(const int&);
	friend bool operator<(const Pair&, const Pair&);
	friend bool operator>(const Pair&, const Pair&);
};

Pair::Pair()
{
	this->first = 0;
	this->second = 0;
}

Pair::Pair(int first, double second)
{
	this->first = first;
	this->second = second;
}

Pair::Pair(const Pair& other)
{
	this->first = other.first;
	this->second = other.second;
}

void Pair::Print()
{
	cout << "(" << this->first << " : " << this->second << ")\n";
}

Pair Pair::operator+(const Pair& p)
{
	return (Pair(this->first + p.first, this->second + p.second));
}

Pair Pair::operator-(const Pair& p)
{
	return (Pair(this->first - p.first, this->second - p.second));
}

void Pair::setFirst(const int& x)
{
	this->first = x;
}

void Pair::setSecond(const double& y)
{
	this->second = y;
}

int Pair::getFirst()
{
	return this->first;
}

double Pair::getSecond()
{
	return this->second;
}

void Pair::operator=(const Pair& p)
{
	this->first = p.first;
	this->second = p.second;
}

ostream& operator <<(ostream& stream, const Pair& p)
{
	stream << "[" << p.first << " : " << p.second << "]";
	return stream;
}

istream& operator >>(istream& stream, Pair& p)
{
	stream >> p.first >> p.second;
	return stream;
}

bool Pair::operator >(const Pair& p)
{
	if (this->first >= p.first && this->second > p.second)
	{
		return true;
	}
	if (this->first > p.first && this->second >= p.second)
	{
		return true;
	}
	return false;
}

bool Pair::operator <(const Pair& p)
{
	if (this->first <= p.first && this->second < p.second)
	{
		return true;
	}
	if (this->first < p.first && this->second <= p.second)
	{
		return true;
	}
	return false;
}

bool operator==(const Pair& pair1, const Pair& pair2) 
{
	return pair1.first == pair2.first && pair1.second == pair2.second;
}

void Pair::operator/(const int& x) 
{
	this->first = this->first / x;
	this->second = this->second / x;
}

bool operator<(const Pair& pair1, const Pair& pair2) 
{
	if (pair1.first <= pair2.first && pair1.first < pair2.first) 
	{
		return true;
	}
	if (pair1.first < pair2.first && pair1.second <= pair2.second) 
	{
		return true;
	}
	return false;
}

bool operator>(const Pair& pair1, const Pair& pair2) 
{
	if (pair1.first >= pair2.first && pair1.first > pair2.first)
	{
		return true;
	}
	if (pair1.first > pair2.first && pair1.second >= pair2.second)
	{
		return true;
	}
	return false;
}
