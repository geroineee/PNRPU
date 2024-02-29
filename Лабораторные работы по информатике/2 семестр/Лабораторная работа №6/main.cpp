#include <iostream>
#include <string>
#include <clocale>
using namespace std;

bool findWord(string word, string *words, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (word == words[i])
        {
            return true;
        }
    }
    return false;
}

void printArr(string *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    string s, words[100], word;
    int k = 0;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (findWord(word, words, k + 1) == false)
                words[k] = word;
            k++;
            word = "";
        }
        else word += s[i];
    }
    printArr(words, k + 1);
    return 0;
}
