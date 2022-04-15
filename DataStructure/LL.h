#pragma once

/*
*	autor: Ond�ej Nedojedl�
*	datum: 2022-04-15 (prvni upravy - git commit)
*	popis: snaha o vytvoreni trid ke sprave datovych struktur
*/


struct node
{
	int data;
	node* next;
};

class LinkedList
{
	node* head; //head linkedlistu
	unsigned int size;//delka L

public:
	LinkedList();
	~LinkedList();

	void printList_index();					//vypise LL a jeho indexy
	void printList();						//vypise LL
	void push_front(int data);				//da na zacatek LL hodnotu
	void push_end(int data);				//da na konec LL hodnotu
	void push_index(int index, int data);	//da na urcity index hodnotu
	int getSize();							//vrati velikost LL
	void pop_last();						//smaze posledni LL hodnotu
	void pop_first();						//smaze prvni LL hodnotu
	void pop_index(int index);				//smaze hodnotu na urcitem indexu
	void reverse();							//obrati cely list (zamena ukazatelu)
};



