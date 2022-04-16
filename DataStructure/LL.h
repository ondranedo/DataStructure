#pragma once

/*
*	autor: Ondøej Nedojedlý
*	datum: 2022-04-15 (prvni upravy - git commit)
*	popis: linked list
*/
namespace ds {

	class LinkedList
	{
		//vzor node
		struct node{
			int data; 
			node* next; 
		};	
		int size;			//delka L
		node* head;			//head linkedlistu

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








}


