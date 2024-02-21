#include <iostream>
using namespace std;

const int n = 5, m = 5;
int num = 1;
int a[m][n];

int main()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i + j) % 2 != 0) a[i][j] = 0;
			else
			{
				if (num % 10 == 0) num = 1;
				a[i][j] = num;
				num++;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}
