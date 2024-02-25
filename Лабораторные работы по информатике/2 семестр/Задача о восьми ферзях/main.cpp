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
    cout << "������� ������ ���������� ����: ";
    cin >> n;
    cout << "������� �������� (� ��������): ";
    cin >> latency;
    queen(0); // ����� ����������� �������
    return 0;
}

void printDesk() // ����� ��������� ����� (������ ����� ������� �� ������� ����� [n])
{
    Sleep(latency * 1000); // �������� ������ ��� �������� ����������
    system("cls"); // ������� �������
    for (int i(0); i < (n * 2 + 5); i++) cout << '=';
    cout << endl;
    for (int i(0); i < n; i++)
    {
        cout << "|| ";
        for (int j(0); j < n; j++)
        {
            if (chessDesk[i][j] == 0)
                cout << '.'; //  '.' - ��������� ������
            else if (chessDesk[i][j] > 0 && chessDesk[i][j] < 9)
                cout << 'x'; // 'x' - "�������" ������
            else
                cout << "Q"; // 'Q' - queen - �����
            cout << ' ';
        }
        cout << "||" << endl; 
    }
    for (int i(0); i < (n * 2 + 5); i++) cout << '=';
    cout << endl;
}

void setQueen(int i, int j)
{
    for (int k(0); k < n; k++) // ��������� �����, ������� ����� ���� �����
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
    chessDesk[i][j] = 9; // ����������� �����
}

void delQueen(int i, int j)
{
    for (int k(0); k < n; k++) // ��������� �����, ������� ��� �����
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
    chessDesk[i][j] = 0; // �������� �����
}

bool queen(int line)
{
    bool flag = false;
    for (int i(0); i < n; i++)
    {
        if (chessDesk[line][i] == 0) // ���� ������ ��������, �� �� ��� ����� ��������  �����
        {
            setQueen(line, i);
            printDesk();
            if (line == n - 1) // ���� ������ ���������, ������ �������� �������
            {
                cout << "������� �������!" << endl;
                Sleep(1000);
                printDesk();
                cout << "����� ���������? ������� 0 ��� 1: ";
                cin >> newReshenie;
                if (newReshenie == false) // ����������� �������� ��� �����
                    flag = true;
                else 
                {
                    delQueen(line, i);
                    flag = false;
                }
            }
            else if (queen(line + 1) == false) // ���� �� ��������� ����� ������ ������ ������,�� ���������� ������������� �����
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
