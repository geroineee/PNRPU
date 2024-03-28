#pragma once
#include <iostream>
using namespace std;


void table_formation(int *shift_table, string &substr)
{
	for (int i = 0; i < 256; i++)
	{
		shift_table[i] = substr.length();
	}
	for (int i = substr.length() - 2; i >= 0; i--)
	{
		if (shift_table[int((unsigned char)substr[i])] == substr.length())
		{
			shift_table[int((unsigned char)substr[i])] = substr.length() - i - 1;
		}
	}
}

int Boiere_Moore(string &str, string &substr, int *shift_table)
{
	int found_index = -1;
	int current_char = substr.length() - 1;
	while (current_char < str.length() && found_index == -1)
	{
		bool flag = true;
		for (int i = substr.length() - 1; i >= 0 && found_index == -1 && flag; i--)
		{
			if (substr[i] != str[current_char - substr.length() + i + 1])
			{
				current_char += shift_table[int((unsigned char)str[current_char - substr.length() + i + 1])];
				flag = false;
			}
			else if (i == 0)
			{
				found_index = current_char - substr.length() + 1;
			}
		}
	}
	return found_index;
}