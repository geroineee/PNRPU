#include <iostream>
using namespace std;

const int n = 5, m = 5;
int num = 1;
int a[m][n];

int main()
{
	int a[100][100], n;
	cout << "Размерность матрицы: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - j + 1 > 0) a[i][j] = i - j + 1;
			else a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}
