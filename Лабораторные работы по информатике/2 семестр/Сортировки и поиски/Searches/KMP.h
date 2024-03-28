#pragma once

#include <iostream>
#include <E:\\source\\repos\\TestCpp\\usefulFuncs.h>

using namespace std;

void prefix_function(string sub_str, int *mas_prefix)
{
    int i = 1, j = 0;
    while (i < sub_str.size())
    {
        if (sub_str[i] == sub_str[j])
        {
            mas_prefix[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                mas_prefix[i] = 0;
                i++;
            }
            else
            {
                j = mas_prefix[j - 1];
            }
        }
    }
}

int KMP_search(string all_str, string sub_str)
{
    int *mas_prefix = new int[sub_str.size()];
    mas_prefix[0] = 0;
    int str_index = 0, substr_index = 0, found_index = -1;
    prefix_function(sub_str, mas_prefix);

    while (str_index < all_str.size() && found_index == -1)
    {
        if (sub_str[substr_index] == all_str[str_index])
        {
            str_index++;
            substr_index++;
        }
        if (substr_index == sub_str.size())
        {
            found_index = str_index - sub_str.size();
        }
        else if (str_index < all_str.size() && sub_str[substr_index] != all_str[str_index]) // если не прошли строку и элементы не совпадают
        {
            if (substr_index == 0)
            {                
                str_index++; 
            }
            else
            {
                substr_index = mas_prefix[substr_index - 1];
            }
        }
    }
    print(mas_prefix, sub_str.size());
    cout << endl;
    delete[] mas_prefix;
    return found_index;
}