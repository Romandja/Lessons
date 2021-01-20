#pragma once
#include <iostream>
#include "Node.h"

class List
{
	Node* head;		//голова списка
	Node* tail;		//хвост списка
	int count;		//количество элементов в списке
public:
	List();
	~List();

	void addToTail(int value);
	void addToHead(int value);
	void removeFromTail();
	void removeFromHead();
	void insert(int value,int);
	void removeAt(int index);
	bool isEmpty();
	void print();
	void clear();
	int get_index(int);
};