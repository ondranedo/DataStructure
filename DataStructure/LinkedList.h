#pragma once

/*
*	autor: Ondøej Nedojedlý
*	datum: y2022m04d15 (prvni upravy - git init commit)
*	obsah: linked list
*				- LL = LinkedList (spojový seznam)
*/


namespace ds {

	///typy vypisu na obrazovku
	//typy format vypisu
	enum class printStyle : int
	{
		INDEX,					//indexovaný výpis	
		ITERATION,				//normlani vypis iteraci
		RECURSION,				//normalni vypis rekurzi
		NORMAL = ITERATION,		//normální výpis			
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

		void printList(printStyle mode) const;	//vypise LL dle zvoleneho modu
		void printList() const;					//vypise LL standartnì STANDARD
		void push_end(int data);				//vloží na konec LL hodnotu
		void push_front(int data);				//vloží na zaèátek LL hodnotu
		void push_index(int index, int data);	//vloží na nThou pozici LL hodnotu
		unsigned long long getSize() const;		//vrátí velikost (poèet prvkù) LL
		void pop_last();						//odstraní poslední hodnotu LL
		void pop_first();						//odstraní první hodnotu LL
		void pop_index(int index);				//odstraní hodnotu LL na nThe pozici
		void reverse(reverseStyle mode);		//prohodi všechny ukazatele LL => obrátí LL
		void reverse();							//prohodi všechny ukazatele LL => obrátí LL - NORMAL
		int locate(int find) const;				//vyhleda v LL hodnotu



		/* - - - - - -private metody - - - - - - */
	private:
		void printList_iter() const;					//vypíše bez indexu iteraci 
		void printList_index() const;					//vypíše s indexem normálnì	
		void printList_recursion(node* t) const;		//vypíše bez indexu rekurzivne
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


