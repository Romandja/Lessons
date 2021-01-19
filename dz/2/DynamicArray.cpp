#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	arr = nullptr;
	capacity = count = 0;
}

DynamicArray::DynamicArray(int capacity)
{
	this->capacity = capacity;
	count = 0;
	arr = new int[capacity];
}

DynamicArray::~DynamicArray()
{
	delete[] arr;
}

void DynamicArray::RemoveAll()
{
	count = 0;
}

void DynamicArray::add(int item)
{
	//массив заполнен
	if (count == capacity) {
		resize(5);
	}
	arr[count++] = item;
}



void DynamicArray::removeAt(int index)
{
	if (this->count >= index)
	{
		for (int i = index; i < this->count; i++)
		{
			this->arr[index] = this->arr[index + 1];
		}
	}
	count--;
}



void DynamicArray::resize(int size)//SetSize
{
	int newSize = capacity + size;
	int* tmp = new int[newSize];
	//копирование эл-ов
	std::copy(arr, tmp, capacity);
	delete[] arr;
	capacity = newSize;
	arr = tmp;
}
int DynamicArray::getCount()
{
	return count;
}
const int* DynamicArray::getData()
{
	return arr;
}

bool DynamicArray::isEmpty()
{
	return count == 0;
}

void DynamicArray::show()
{
	std::cout << "-= Elements =-" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(3) << arr[i];
	}
	std::cout << std::endl;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& copy)
{
	this->capacity = copy.capacity;
	this->count = copy.count;
	int *tmp = new int[capacity];
	std::copy(this->arr, tmp, this->capacity);
	delete[] arr;
	arr = tmp;
	return *this;
}

int DynamicArray::operator[](int index)
{
	int tmp;
	if (count >= index)
	{
		tmp = arr[index];
	}
	return tmp;
}

int DynamicArray::GetAT(int index)
{
	int tmp;
	if (this->count >= index)
	{
		tmp = this->arr[index];
	}
	return tmp;
}

void DynamicArray::SetAt(int index, int value)
{
	if (this->count >= index)
	{
		this->arr[index] = value;
	}
	else
	{
		show();
	}
}

void DynamicArray::InsertAt(int index, int value)
{
	SetAt(index, value);
}

int DynamicArray::GetUpperBound()
{
	return (count - 1);
}

DynamicArray& DynamicArray::Append(const DynamicArray& copy)
{
	
	if (this->capacity <= (this->count + copy.count) )
	{
		resize(copy.count);
	}
	for (int i = count; i < (this->count + copy.count); i++)
	{
		this->arr[i] = copy.arr[i];
	}
	this->count += copy.count;
	return *this;
}
