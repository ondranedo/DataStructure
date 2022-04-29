#pragma once
#include "pch.h"
/*
 *	autor: Ond�ej Nedojedl�
 *	datum: y2022m04d15 (prvni upravy - git init commit)
 */

namespace ds
{

	/*
		Spojov� seznam obsahuj�c� data typu 'int'.
		Adresu na dalsi node, a node p�edchoz�,
		asymptotick� slo�itost pro funkci push_end(), pro ohrani�eni shora je konstanta 1,
		av�ak v�t�� jedna node o jeden ukazatel
		[u 64b arch. pointer = 8B; u 32b arch. pointer = 4B]
		=> v�hodn�j�� u vy��� velikost payloadu(=data krom� ukazatelu na dal�i node)
		node(= jeden prvek soub�zn� pam�ti obsahuj�c� 2*node poniter a payload)
	*/
	template<class T>
	class LinkedList
	{
	private:
		/* - - - - - - dal�� prvky - - - - - - */
		struct node
		{
			T data;
			node *next;
			node *prev;
		};

		/* - - - - - - prom�nn� - - - - - - */
		size_t size;
		node *head;
		node *tail;

	public:
		/// public metodu
		// p�id� hodnotu na za��tek
		void push_front(T data);

		// p�id� hodnotu na konec
		void push_end(T data);

		// p�id� hodnotu na ur�it� index
		void push_index(size_t index, T data);

		// sma�e prvn� hodnotu
		T pop_first();

		// sma�e posledn� hodnotu
		T pop_last();

		// sma�e hodnotu z ur�it�ho indexu
		T pop_index(size_t index);

		// vr�ti hodnotu velikosti pole
		size_t getSize() const;

		// vztiskne LL na jeden ��dek
		void printList() const;

		//smaze stack
		void clearLinkedList();

		/// konstruktory dekonstruktory
		LinkedList();
		~LinkedList();

	private:
	};
}
using namespace ds;
template<class T>
LinkedList<T>::LinkedList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template<class T>
LinkedList<T>::~LinkedList()
{
	clearLinkedList();
}
template<class T>
void LinkedList<T>::printList() const
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
template<class T>
void LinkedList<T>::clearLinkedList()
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
template<class T>
size_t LinkedList<T>::getSize() const
{
	return size;
}

//funkce vložení
template<class T>
void LinkedList<T>::push_front(T data)
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
template<class T>
void LinkedList<T>::push_end(T data)
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
template<class T>
void LinkedList<T>::push_index(size_t index, T data)
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
template<class T>
T LinkedList<T>::pop_first()
{
	T rVal;
	if (tail == NULL) return -1;
	size--;
	node* tmp = head;
	rVal = tmp->data;
	head = head->next;
	head->prev = nullptr;
	delete tmp;
	return rVal;
}
template<class T>
T LinkedList<T>::pop_last()
{
	T rVal;
	if (tail == NULL) return -1;
	size--;
	node* tmp = tail;
	rVal = tmp->data;
	tail = tail->prev;
	tail->next = nullptr;
	delete tmp;
	return rVal;
}
template<class T>
T LinkedList<T>::pop_index(size_t index)
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
	T rVal;
	//smaze node a upravi pointry
	size--;
	tmp->next->next->prev = tmp;
	node* del = tmp->next;
	rVal = del->data;
	tmp->next = del->next;
	delete del;
	return rVal;
}