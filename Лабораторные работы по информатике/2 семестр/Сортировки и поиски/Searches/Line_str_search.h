#pragma once
#include <iostream>
using namespace std;


int line_str_search(string &str, string &substr)
{
	bool is_found;
	for (int i = 0; i <= str.length() - substr.length(); i++)
	{
		is_found = true;
		if (str[i] == substr[0])
		{
			for (int j = 1; j < substr.length() && is_found; j++)
			{
				is_found = (str[i + j] == substr[j]);
			}
			if (is_found)
			{
				return i;
			}
		}
	}
	return -1;
}