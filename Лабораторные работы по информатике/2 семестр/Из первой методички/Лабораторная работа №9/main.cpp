#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string lines[100]; // массив строк
    int j = 0;         // индекс последнего элемента
    int n = 1, n1, n2;
    cout << "Введите N1 и N2: ";
    cin >> n1 >> n2;
    string line;
    ifstream F1("F1.txt"); // чтение файла
    ofstream F2("F2.txt"); // запись файла
    while (getline(F1, line))
    {
        if (n <= n2 && n >= n1 && (line[0] == 'A'))
            F2 << line << endl;
        if (n >= (n2 + 2))
        {
            lines[j] = line;
            j++;
        }
        n++;
    }
    for (int i = 0; i < j + 1; i++)
        F2 << lines[i] << endl;
    int cnt = 1;
    j--;
    for (int i=0; lines[j][i] != '\0';i++)
    {
        if (lines[j][i] == ' ' && lines[j][i+1] != ' ')
        {
            cnt++;
        }
    }
    cout << "Количество слов в последней строчке файла F2: " << cnt;
    F1.close();
    F2.close();
    return 0;
}