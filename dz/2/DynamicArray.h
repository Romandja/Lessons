#pragma once
#include <iostream>
#include <iomanip>

class DynamicArray {
	int* arr;
	int capacity;						//общий размер
	int count;							//фактическое кол-во эл-ов
public:
	DynamicArray();
	DynamicArray(int capacity);
	~DynamicArray();
	void RemoveAll();					//RemoveAll

	void add(int item);					//add
	
	void removeAt(int index);

	void resize(int size);				//SetSize
	int getCount();						//GetSize
	const int* getData();				//getData

	bool isEmpty();
	void show();
	DynamicArray& operator=(const DynamicArray&);
	int operator[](int);
	int GetAT(int);
	void SetAt(int, int);
	void InsertAt(int, int);
	int GetUpperBound();
	DynamicArray& Append(const DynamicArray&);
};
