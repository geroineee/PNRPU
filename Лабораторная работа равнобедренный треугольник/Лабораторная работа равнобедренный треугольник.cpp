#include <iostream>
#include <clocale>
using namespace std;

int main()
{
	int N = 0, spaces, stars;
	while (N <= 0 || N % 2 == 0)
	{
		cout << "Введите основание равнобедреннго треугольника: ";
		cin >> N;
		cout << endl;
	}
	stars = 1;
	spaces = N / 2;
	for (int i = 1; i <= (N / 2) + 1; i++)
	{
		for (int j = 1; j <= spaces; j++) cout << ' ';
		for (int j = 1; j <= stars; j++) cout << '*';
		cout << endl;
		stars += 2;
		spaces -= 1;
	}
}
