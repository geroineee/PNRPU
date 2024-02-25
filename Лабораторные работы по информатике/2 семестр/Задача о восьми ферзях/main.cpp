#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;


int chessDesk[100][100];
int n;
bool newReshenie;
float latency;


void printDesk();
void setQueen(int i, int j);
void delQueen(int i, int j);
bool queen(int line);



int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите размер шахматного поля: ";
    cin >> n;
    cout << "Введите задержку (в секундах): ";
    cin >> latency;
    queen(0); // вызов рекурсивной функции
    return 0;
}

void printDesk() // Вывод шахматной доски (размер рамок зависит от размера доски [n])
{
    Sleep(latency * 1000); // Задержка вывода для удобного восприятия
    system("cls"); // Очистка консоли
    for (int i(0); i < (n * 2 + 5); i++) cout << '=';
    cout << endl;
    for (int i(0); i < n; i++)
    {
        cout << "|| ";
        for (int j(0); j < n; j++)
        {
            if (chessDesk[i][j] == 0)
                cout << '.'; //  '.' - свободная клетка
            else if (chessDesk[i][j] > 0 && chessDesk[i][j] < 9)
                cout << 'x'; // 'x' - "занятые" клетки
            else
                cout << "Q"; // 'Q' - queen - ферзь
            cout << ' ';
        }
        cout << "||" << endl; 
    }
    for (int i(0); i < (n * 2 + 5); i++) cout << '=';
    cout << endl;
}

void setQueen(int i, int j)
{
    for (int k(0); k < n; k++) // изменения полей, которые может бить ферзь
    {
        int b;
        chessDesk[i][k] += 1;
        chessDesk[k][j] += 1;
        b = j - i + k;
        if (b >= 0 && b < n)
            chessDesk[k][b] += 1;
        b = j + i - k;
        if (b >= 0 && b < n)
            chessDesk[k][b] += 1;
    }
    chessDesk[i][j] = 9; // выставление ферзя
}

void delQueen(int i, int j)
{
    for (int k(0); k < n; k++) // изменения полей, которые бил ферзь
    {
        int b;
        chessDesk[i][k] -= 1;
        chessDesk[k][j] -= 1;
        b = j - i + k;
        if (b >= 0 && b < n)
            chessDesk[k][b] -= 1;
        b = j + i - k;
        if (b >= 0 && b < n)
            chessDesk[k][b] -= 1;
    }
    chessDesk[i][j] = 0; // удаление ферзя
}

bool queen(int line)
{
    bool flag = false;
    for (int i(0); i < n; i++)
    {
        if (chessDesk[line][i] == 0) // если клетка свободна, то на это место ставится  ферзь
        {
            setQueen(line, i);
            printDesk();
            if (line == n - 1) // если строка последняя, значит решейние найдено
            {
                cout << "Решение найдено!" << endl;
                Sleep(1000);
                printDesk();
                cout << "Найти следующее? Введите 0 или 1: ";
                cin >> newReshenie;
                if (newReshenie == false) // продолжение рекурсии или выход
                    flag = true;
                else 
                {
                    delQueen(line, i);
                    flag = false;
                }
            }
            else if (queen(line + 1) == false) // если на следующих шагах нельзя решить задачу,то откатываем поставленного ферзя
            {
                flag = false;
                delQueen(line, i);
                printDesk();
            }
            else flag = true;
        }
    }
    return flag;
}
