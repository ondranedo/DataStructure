#include "pch.h"
#include "LinkedList.h"

using namespace ds;

LinkedList::LinkedList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
LinkedList::~LinkedList()
{
	delete head;
}

void LinkedList::printList() const
{
	node* tmp = head;
	while (tmp != NULL)
	{

		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
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
	if (index > size+1 || index < 0)
	{
		std::cout << "@push_index index error" << std::endl;
		return;
	}
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

	if (index == size) { push_end(data); return; }

	node* tmp = nullptr;
	node* _new = nullptr;

	//potrebujeme pocitat od zacatku
	if (index < size / 2)
	{
		tmp = head;
		for (size_t i = 1; i < index-1; i++)
			tmp = tmp->next;
		_new = new node;
		_new->data = data;

		_new->next = tmp->next;
		_new->prev = tmp;
		tmp->next = _new;
		_new->next->prev = _new;

		size++;
		return;
	}

	//potrebujeme pocitat od konce
	if (index >= size / 2)
	{
		tmp = tail;
		for (size_t i = size; i > index; i--)
			tmp = tmp->prev;

		_new = new node;
		_new->data = data;

		_new->next = tmp;
		_new->prev = tmp->prev;
		tmp->prev->next = _new;
		tmp->prev = _new;


		size++;
		return;
	}

}