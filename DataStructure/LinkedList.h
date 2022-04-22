#pragma once

/*
*	autor: Ondøej Nedojedlý
*	datum: y2022m04d15 (prvni upravy - git init commit)
*	obsah: linked list
*				- LL = LinkedList (spojový seznam)
*/

namespace ds {

	///typy výpisu na obrazovku
	//typy formát vypisu
	enum class printStyle : int
	{
		INDEX,					//indexovaný výpis	
		ITERATION,				//normlani vypis iteraci
		RECURSION,				//normalni vypis rekurzi
		NORMAL = ITERATION,		//normální výpis			
	};

	//typy a vypisu seøazeni
	enum class reverseStyle {
		ITERATION,				//serazeni pole iteraci
		RECURSION,				//serazeni pole rekurzi
		NORMAL = ITERATION,		//normalni serazeni
	};

	///tøídy
	//spojový seznam s pouze dalši adresou
	class SingleLinkedList
	{
		/*  - - - - - -private primitivní datové struktury - - - - - - */
		/*
		*	struktura kde jedna èást pamìti pøedstavuje
		*	jeden tzv. "node", což je jeden prvek
		*	spojového seznamu
		*/
		struct node {
			int data;
			node* next;
		};


		/* - - - - - - private promìnné - - - - - - */
		unsigned long long size;		//délka L
		node* head;						//head linkedlist


		/* - - - - - - public metody - - - - - - */
	public:
		SingleLinkedList();
		~SingleLinkedList();

		void printList(printStyle mode) const;	//vypíše LL dle zvoleneho módu
		void printList() const;					//vypíše LL standartnì STANDARD
		void push_end(int data);				//vloží na konec LL hodnotu
		void push_front(int data);				//vloží na zaèátek LL hodnotu
		void push_index(int index, int data);	//vloží na nThou pozici LL hodnotu
		unsigned long long getSize() const;		//vrátí velikost (poèet prvkù) LL
		void pop_last();						//odstraní poslední hodnotu LL
		void pop_first();						//odstraní první hodnotu LL
		void pop_index(int index);				//odstraní hodnotu LL na nThe pozici
		void reverse(reverseStyle mode);		//prohodi všechny ukazatele LL => obrátí LL
		void reverse();							//prohodi všechny ukazatele LL => obrátí LL - NORMAL
		int locate(int find) const;				//vyhledá v LL hodnotu



		/* - - - - - -private metody - - - - - - */
	private:
		void printList_iter() const;					//vypíše bez indexu iteraci 
		void printList_index() const;					//vypíše s indexem normálnì	
		void printList_recursion(node* t) const;		//vypíše bez indexu rekurzivne
		void reverse_recursion(node* tmp);				//obrátí LL pres rekurzy
		void reverse_iter();							//obrátí LL pres iteraci
	};

	//spojový seznam se dvìma adresami
	class LinkedList
	{
	private:
		/* - - - - - - další prvky - - - - - - */
		struct node {
			int data;
			node* next;
			node* prev;
		};


		/* - - - - - - promìnné - - - - - - */
		size_t size;
		node* head;
		node* tail;


	public:
		///public metodu
		//pøidá hodnotu na zaèátek
		void push_front(int data);

		//pøidá hodnotu na konec
		void push_end(int data);

		//pøidá hodnotu na urèitý index
		void push_index(size_t index, int data);
		/*
				//smaže první hodnotu
				void pop_first();

				//smaže poslední hodnotu
				void pop_last();

				//smaže hodnotu z urèitého indexu
				void pop_index(size_t index);
		*/
		//vráti hodnotu velikosti pole
		size_t getSize() const;
		
		//vztiskne LL na jeden øádek
		void printList() const;

		///konstruktory dekonstruktory
		LinkedList();
		~LinkedList();
	private:
	};
}


