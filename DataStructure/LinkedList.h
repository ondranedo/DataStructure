#pragma once

/*
*	autor: Ond�ej Nedojedl�
*	datum: y2022m04d15 (prvni upravy - git init commit)
*	obsah: linked list
*				- LL = LinkedList (spojov� seznam)
*/

namespace ds {

	///typy v�pisu na obrazovku
	//typy form�t vypisu
	enum class printStyle : int
	{
		INDEX,					//indexovan� v�pis	
		ITERATION,				//normlani vypis iteraci
		RECURSION,				//normalni vypis rekurzi
		NORMAL = ITERATION,		//norm�ln� v�pis			
	};

	//typy a vypisu se�azeni
	enum class reverseStyle {
		ITERATION,				//serazeni pole iteraci
		RECURSION,				//serazeni pole rekurzi
		NORMAL = ITERATION,		//normalni serazeni
	};

	///t��dy
	//spojov� seznam s pouze dal�i adresou
	class SingleLinkedList
	{
		/*  - - - - - -private primitivn� datov� struktury - - - - - - */
		/*
		*	struktura kde jedna ��st pam�ti p�edstavuje
		*	jeden tzv. "node", co� je jeden prvek
		*	spojov�ho seznamu
		*/
		struct node {
			int data;
			node* next;
		};


		/* - - - - - - private prom�nn� - - - - - - */
		unsigned long long size;		//d�lka L
		node* head;						//head linkedlist


		/* - - - - - - public metody - - - - - - */
	public:
		SingleLinkedList();
		~SingleLinkedList();

		void printList(printStyle mode) const;	//vyp�e LL dle zvoleneho m�du
		void printList() const;					//vyp�e LL standartn� STANDARD
		void push_end(int data);				//vlo�� na konec LL hodnotu
		void push_front(int data);				//vlo�� na za��tek LL hodnotu
		void push_index(int index, int data);	//vlo�� na nThou pozici LL hodnotu
		unsigned long long getSize() const;		//vr�t� velikost (po�et prvk�) LL
		void pop_last();						//odstran� posledn� hodnotu LL
		void pop_first();						//odstran� prvn� hodnotu LL
		void pop_index(int index);				//odstran� hodnotu LL na nThe pozici
		void reverse(reverseStyle mode);		//prohodi v�echny ukazatele LL => obr�t� LL
		void reverse();							//prohodi v�echny ukazatele LL => obr�t� LL - NORMAL
		int locate(int find) const;				//vyhled� v LL hodnotu



		/* - - - - - -private metody - - - - - - */
	private:
		void printList_iter() const;					//vyp�e bez indexu iteraci 
		void printList_index() const;					//vyp�e s indexem norm�ln�	
		void printList_recursion(node* t) const;		//vyp�e bez indexu rekurzivne
		void reverse_recursion(node* tmp);				//obr�t� LL pres rekurzy
		void reverse_iter();							//obr�t� LL pres iteraci
	};

	//spojov� seznam se dv�ma adresami
	class LinkedList
	{
	private:
		/* - - - - - - dal�� prvky - - - - - - */
		struct node {
			int data;
			node* next;
			node* prev;
		};


		/* - - - - - - prom�nn� - - - - - - */
		size_t size;
		node* head;
		node* tail;


	public:
		///public metodu
		//p�id� hodnotu na za��tek
		void push_front(int data);

		//p�id� hodnotu na konec
		void push_end(int data);

		//p�id� hodnotu na ur�it� index
		void push_index(size_t index, int data);
		/*
				//sma�e prvn� hodnotu
				void pop_first();

				//sma�e posledn� hodnotu
				void pop_last();

				//sma�e hodnotu z ur�it�ho indexu
				void pop_index(size_t index);
		*/
		//vr�ti hodnotu velikosti pole
		size_t getSize() const;
		
		//vztiskne LL na jeden ��dek
		void printList() const;

		///konstruktory dekonstruktory
		LinkedList();
		~LinkedList();
	private:
	};
}


