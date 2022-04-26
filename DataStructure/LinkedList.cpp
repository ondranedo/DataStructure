#include "pch.h"

using namespace ds;

LinkedList::LinkedList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
LinkedList::~LinkedList()
{
	clearLinkedList();
}

void LinkedList::printList() const
{
	if (head == NULL) return;
	node* tmp = head;
	while (tmp != NULL)
	{

		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void LinkedList::clearLinkedList()
{
	if (head == NULL) return;
	node* tmp = head;
	node* _next = tmp->next;

	while (tmp->next != NULL)
	{
		delete tmp;
		tmp = _next;
		_next = _next->next;
	}
	head = NULL;
	tail = NULL;
	size = 0;
}

//setters a getters
size_t LinkedList::getSize() const
{
	return size;
}

//funkce vložení
void LinkedList::push_front(int data)
{
	size++;
	if (head == NULL)
	{
		head = new node;
		head->data = data;
		head->next = nullptr;
		head->prev = nullptr;
		tail = head;
		return;
	}
	node* tmp = head;
	head = new node;
	head->data = data;
	head->next = tmp;
	head->prev = nullptr;
	tmp->prev = head;
}
void LinkedList::push_end(int data)
{
	size++;
	if (tail == NULL)
	{
		tail = new node;
		tail->data = data;
		tail->next = nullptr;
		tail->prev = nullptr;
		head = tail;
		return;
	}
	node* tmp = tail;
	tail = new node;
	tail->data = data;
	tail->next = nullptr;
	tail->prev = tmp;
	tmp->next = tail;
}
void LinkedList::push_index(size_t index, int data)
{
	//kontroly
	if (head == NULL)
	{
		tail = new node;
		tail->data = data;
		tail->next = nullptr;
		tail->prev = nullptr;
		head = tail;
		size++;
		return;
	}
	if (index == 1) { push_front(data); return; }
	if (index == size) { push_end(data); return; }
	if (index > size + 1 || index <= 0)
	{
		std::cout << "@push_index index error" << std::endl;
		return;
	}

	//pomocne ukazatele
	node* tmp = nullptr;

	//najde node pred nodem ktery se ma smazat od head
	if (index < size / 2)
	{
		tmp = head;
		for (size_t i = 1; i < index - 1; i++)
			tmp = tmp->next;
	}

	//najde node pred nodem ktery se ma smazat od tailu
	if (index >= size / 2)
	{
		tmp = tail;
		for (size_t i = size; i >= index; i--)
			tmp = tmp->prev;
	}
	size++;
	node* _new = new node;
	_new->data = data;
	_new->next = tmp->next;
	_new->prev = tmp;
	tmp->next = _new;
}

int LinkedList::pop_first()
{
	int rVal;
	if (tail == NULL) return -1;
	size--;
	node* tmp = head;
	rVal = tmp->data;
	head = head->next;
	head->prev = nullptr;
	delete tmp;
	return rVal;
}
int LinkedList::pop_last()
{
	int rVal;
	if (tail == NULL) return -1;
	size--;
	node* tmp = tail;
	rVal = tmp->data;
	tail = tail->prev;
	tail->next = nullptr;
	delete tmp;
	return rVal;
}
int LinkedList::pop_index(size_t index)
{
	//kontroly
	if (tail == NULL) return -1;
	if (index > size || index <= 0)
	{
		std::cout << "@push_index index error" << std::endl; return -1;
	}
	if (index == 1)
	{ 
		return pop_first();
	}
	if (index == size)
	{ 
		return pop_last();
	}

	//pomocne ukazatele
	node* tmp = nullptr;

	//najde node pred nodem ktery se ma smazat od head
	if (index < size / 2)
	{
		tmp = head;
		for (size_t i = 1; i < index-1; i++)
			tmp = tmp->next;
	}

	//najde node pred nodem ktery se ma smazat od tailu
	if (index >= size / 2)
	{
		tmp = tail;
		for (size_t i = size; i >= index; i--)
			tmp = tmp->prev;
	}
	int rVal;
	//smaze node a upravi pointry
	size--;
	tmp->next->next->prev = tmp;
	node* del = tmp->next;
	rVal = del->data;
	tmp->next = del->next;
	delete del;
	return rVal;
}