#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node *next_ptr = nullptr;
};

class List
{
public:
	Node *head = nullptr;
	Node *tail = nullptr;
	int size = 0;

	void pop_front();
	void push_back(int);
	void push_front(int);
	void pop_back();
	Node *getAt(int);
	void insert(int, int);
	void erase(int);
	void print();

	~List();
	int &operator[](int);
	List &operator()(int);
	List &operator+=(int);

	friend List &operator*(List &a, vector<int> b);
};