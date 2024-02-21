#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RU");
    int a[100][100], n, m;
    cout << "Введите размер массива (n и m): " << endl;
    cin >> n;
    cin >> m;
    cout << "Введите элементы массива: " << endl;
    for (int raw = 0; raw < n; raw++) // формирование двумерного массива
    {
        for (int column = 0; column < m; column++)
        {
            a[raw][column] = rand() % 15;
            cout << a[raw][column] << '\t';
        }
        cout << endl;
    }
    int raw_max = 0, column_max = 0; // идентификатор массива с максимальной суммой
    int summ_max = 0;                // переменная для подсчета суммы
    for (int raw = 0; raw < n - 2; raw++)
    {
        for (int column = 0; column < m - 2; column++) 
        {
            int summ = 0;
            for (int i = raw; i < raw + 3; i++) // подсчёт суммы элементов матрицы размером 3х3
            {
                for (int j = column; j < column + 3; j++)
                {
                    summ += a[i][j];
                }
            }
            if (summ > summ_max) // запоминаем максимальную сумму и идентификатор матрицы
            {
                summ_max = summ;
                raw_max = raw;
                column_max = column;
            }
        }
    }
    cout << endl << "Максимальная сумма: " << summ_max << endl;
    cout << "Идентификатор массива (индексы левого верхнего элемента массива): " << raw_max + 1 << ' ' << column_max + 1 << endl;
    for (int i = raw_max; i < raw_max + 3; i++) // вывод матрицы 3х3
            {
                for (int j = column_max; j < column_max + 3; j++)
                {
                    cout << a[i][j] << '\t';
                }
                cout << endl;
            }
}
