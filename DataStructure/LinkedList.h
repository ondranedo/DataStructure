#pragma once

/*
*	autor: Ond�ej Nedojedl�
*	datum: y2022m04d15 (prvni upravy - git init commit)
*	obsah: linked list
*				- LL = LinkedList (spojov� seznam)
*/


namespace ds {

	///typy vypisu na obrazovku
	//typy format vypisu
	enum class printStyle : int
	{
		INDEX,					//indexovan� v�pis	
		ITERATION,				//normlani vypis iteraci
		RECURSION,				//normalni vypis rekurzi
		NORMAL = ITERATION,		//norm�ln� v�pis			
	};
	//typy a zpusob serayeni
	enum class reverseStyle {
		ITERATION,				//serazeni pole iteraci
		RECURSION,				//serazeni pole rekurzi
		NORMAL = ITERATION,		//normalni serazeni
	};

	///tridy
	//spojovy seznam s pouze dalsi adresou
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

		void printList(printStyle mode) const;	//vypise LL dle zvoleneho modu
		void printList() const;					//vypise LL standartn� STANDARD
		void push_end(int data);				//vlo�� na konec LL hodnotu
		void push_front(int data);				//vlo�� na za��tek LL hodnotu
		void push_index(int index, int data);	//vlo�� na nThou pozici LL hodnotu
		unsigned long long getSize() const;		//vr�t� velikost (po�et prvk�) LL
		void pop_last();						//odstran� posledn� hodnotu LL
		void pop_first();						//odstran� prvn� hodnotu LL
		void pop_index(int index);				//odstran� hodnotu LL na nThe pozici
		void reverse(reverseStyle mode);		//prohodi v�echny ukazatele LL => obr�t� LL
		void reverse();							//prohodi v�echny ukazatele LL => obr�t� LL - NORMAL
		int locate(int find) const;				//vyhleda v LL hodnotu



		/* - - - - - -private metody - - - - - - */
	private:
		void printList_iter() const;					//vyp�e bez indexu iteraci 
		void printList_index() const;					//vyp�e s indexem norm�ln�	
		void printList_recursion(node* t) const;		//vyp�e bez indexu rekurzivne
		void reverse_recursion(node* tmp);				//obrati LL pres rekurzy
		void reverse_iter();							//obrati LL pres iteraci
	};

	//spojovy seznam se dvema adresama
	class LinkedList
	{
	private:
		/* - - - - - - dalsi prvky - - - - - - */
		struct node {
			int data;
			node* next;
			node* prev;
		};


		/* - - - - - - promenne - - - - - - */
		size_t size;
		node* head;
		node* tail;


	public:
		///public metodu
		//prida hodnotu na zacatek
		void push_front(int data);
/*
		//prida hodnotu na konec
		void push_end(DATA_TYPE data);

		//prida hodnotu na urcity index
		void push_index(DATA_TYPE data, size_t index);

		//smaze prvni hodnotu
		void pop_first();				

		//smaze posledni hodnotu
		void pop_last(); 

		//smaze hodnotu z urciteho indexu 
		void pop_index(size_t index);
		
		//vrati hodnotu velikosti pole
		size_t getSize() const;
*/

		///konstruktory dekonstruktory
		LinkedList();
		~LinkedList();
	private:
	};


}


