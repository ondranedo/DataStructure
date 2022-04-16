#pragma once

/*
*	autor: Ondøej Nedojedlý
*	datum: 2022-04-15 (prvni upravy - git commit)
*	popis: linked list
*	LL = LinkedList (spojový seznam)
*/
namespace ds {
	
/* - - - - - - - - - Enumerace a další - - - - - - - - - - */

	///typy vypisu na obratovku
	enum class printStyle : int
	{
		BLANK = 0,			// prazda hodnota		
		INDEX = 1 << 0,		// indexovaný výpis	
		NORMAL = 1 << 1,	// normální výpis		
		REVERSED = 1 << 2,	// vypíše LL pozpátku	
	};


/* - - - - - - - - - Enumerace a další - - - - - - - - - - */
	class LinkedList
	{
		/* - - - - - private primitivní datové struktury - - - - - */
		/*
		*	struktura kde jedna èást pamìti pøedstavuje
		*	jeden tzv. "node", což je jeden prvek
		*	spojového seznamu	
		*/
		struct node{
			int data; 
			node* next; 
		};	


		/* - - - - - - - - private promìnné - - - - - - - - - - */
		int size;			//delka L
		node* head;			//head linkedlist


		/* - - - - - - - - public metody - - - - - - - - - - */
	public:
		LinkedList();
		~LinkedList();

		void printList(printStyle mode);		//vypise LL dle zvoleneho modu
		void printList()				;		//vypise LL standartnì STANDARD
		void push_end(int data);				//vloží na konec LL hodnotu
		void push_front(int data);				//vloží na zaèátek LL hodnotu
		void push_index(int index, int data);	//vloží na nThou pozici LL hodnotu
		int getSize();							//vrátí velikost (poèet prvkù) LL
		void pop_last();						//odstraní poslední hodnotu LL
		void pop_first();						//odstraní první hodnotu LL
		void pop_index(int index);				//odstraní hodnotu LL na nThe pozici
		void reverse();							//prohodá všechny ukazatele LL => obrátí LL
	



		/* - - - - - - - - private metody - - - - - - - - - - */
	private:
		void printList_normal(node* t);			//vypíše bez indexu normálnì 
		void printList_reversed(node* t);		//vypíše bez indexu pozpátku 
		void printList_index();			//vypíše s indexem normálnì	
		
	};
}


