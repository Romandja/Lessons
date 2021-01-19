#include "List.h"

List::List()
{
	head = tail = nullptr;
	count = 0;
}

List::~List()
{
	clear();
}

void List::addToTail(int value)
{
	//новый узел
	Node* node = new Node;
	node->value = value;

	//список пуст (добавление первого элемента)
	if (isEmpty()) {
		head = tail = node;
	}
	else {	//список не пуст
		tail->next = node;
		tail = node;
	}
	count++;
}

void List::addToHead(int value)
{
	//новый узел
	Node* node = new Node;
	node->value = value;

	//список пуст (добавление первого элемента)
	if (isEmpty()) {
		head = tail = node;
	}
	else {
		node->next = head;
		head = node;
	}
	count++;
}

void List::removeFromTail()
{
	//список не пуст
	if (!isEmpty()) {
		//временный указатель для прохода по списку
		Node* tmp = head;

		//перебор списка
		while (tmp->next != nullptr && tmp->next != tail) {
			tmp = tmp->next;
		}


		if (count == 1) {
			delete tmp;
			head = tail = nullptr;
		}
		else {
			delete tail;
			tail = tmp;
			tail->next = nullptr;
		}

		count--;
	}
}

void List::removeFromHead()
{
	//список не пуст
	if (!isEmpty()) {
		Node* tmp = head->next;
		delete head;
		head = tmp;
		count--;
	}
}

void List::insert(int value,int index)
{
	//список не пуст & индекс не выходит за предел списка
	if (!isEmpty() && index < count -1) 
	{
		//временный указаетель для прохода по списку
		Node* tmp = head;
		
		for (int idx = 0; idx < index; idx++)
		{
			tmp = tmp->next;
		}
		tmp->value = value;
		for (int idx = index; idx < count; idx++)
		{
			tmp = tmp->next;
		}
	}
}

void List::removeAt(int index)
{
	//список не пуст & индекс не выходит за предел списка
	if (!isEmpty() && index < count - 1) {
		//временный указаетель для прохода по списку
		Node* tmp = head;

		for (int idx = 0; idx < index - 1; idx++)
		{
			tmp = tmp->next;
		}
		//правая часть списка
		Node* right = tmp->next->next;
		delete tmp->next;
		tmp->next = right;
	}
}

bool List::isEmpty()
{
	return head == nullptr;
}

void List::print()
{
	//временный указаетель для прохода по списку
	Node* tmp = head;

	if (!isEmpty()) {
		while (tmp != nullptr) {
			std::cout << tmp->value << " ";
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}
}

void List::clear()
{
	if (!isEmpty()) {
		//временный указатель для прохода по списку
		/*Node* tmp = head;

		while (tmp != nullptr) {
			tmp = tmp->next;
			delete head;
			head = tmp;
		}
		head = tail = nullptr;*/

		while (!isEmpty()) {
			removeFromHead();
		}
		head = tail = nullptr;
	}
}

int List::get_index(int value)
{
	int index = -1;
	
	if (!isEmpty() && index < count - 1)
	{
		Node* tmp = head;
		for (int i = 0; i < count; i++)
		{
			if (tmp->value == value)
			{
				index = ++i;
				break;
			}
			tmp = tmp->next;
		}
	}
	return index;
}
