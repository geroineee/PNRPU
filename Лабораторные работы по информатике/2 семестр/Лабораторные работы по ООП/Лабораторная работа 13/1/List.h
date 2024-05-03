#pragma once
#include <iostream>
#include <istream>
#include <list>
#include "pair.h"

using namespace std;

class List : public list<Pair>
{
public:
    int size = 0;
    void print()
    {
        int cnt = 0;
        for (list<Pair>::iterator i = this->begin(); i != this->end(); i++)
        {
            cout << *i << ' ';
            cnt++;
        }
        if (!cnt)
            cout << "Список пуст!\n";
        else
            cout << endl;
    }

    void fill_list(int n)
    {
        Pair temp_pair;
        for (int i = 0; i < n; i++)
        {
            cin >> temp_pair;
            this->add_back(temp_pair);
        }
    }

    void add_back(Pair &pair)
    {
        this->push_back(pair);
        size++;
    }

    void insert_pair(int k, Pair &temp_pair)
    {
        int position = 1;
        for (list<Pair>::iterator iter = this->begin(); iter != this->end(); iter++)
        {
            if (position == k)
            {
                this->insert(iter, 1, temp_pair);
                size++;
            }
            position++;
        }
    }
};