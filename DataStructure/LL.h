#pragma once

/*
*	autor: Ond�ej Nedojedl�
*	datum: 2022-04-15 (prvni upravy - git commit)
*	popis: linked list
*	LL = LinkedList (spojov� seznam)
*/
namespace ds {
	
/* - - - - - - - - - Enumerace a dal�� - - - - - - - - - - */

	///typy vypisu na obratovku
	enum class printStyle : int
	{
		BLANK = 0,			// prazda hodnota		
		INDEX = 1 << 0,		// indexovan� v�pis	
		NORMAL = 1 << 1,	// norm�ln� v�pis		
		REVERSED = 1 << 2,	// vyp�e LL pozp�tku	
	};


/* - - - - - - - - - Enumerace a dal�� - - - - - - - - - - */
	class LinkedList
	{
		/* - - - - - private primitivn� datov� struktury - - - - - */
		/*
		*	struktura kde jedna ��st pam�ti p�edstavuje
		*	jeden tzv. "node", co� je jeden prvek
		*	spojov�ho seznamu	
		*/
		struct node{
			int data; 
			node* next; 
		};	


		/* - - - - - - - - private prom�nn� - - - - - - - - - - */
		int size;			//delka L
		node* head;			//head linkedlist


		/* - - - - - - - - public metody - - - - - - - - - - */
	public:
		LinkedList();
		~LinkedList();

		void printList(printStyle mode);		//vypise LL dle zvoleneho modu
		void printList()				;		//vypise LL standartn� STANDARD
		void push_end(int data);				//vlo�� na konec LL hodnotu
		void push_front(int data);				//vlo�� na za��tek LL hodnotu
		void push_index(int index, int data);	//vlo�� na nThou pozici LL hodnotu
		int getSize();							//vr�t� velikost (po�et prvk�) LL
		void pop_last();						//odstran� posledn� hodnotu LL
		void pop_first();						//odstran� prvn� hodnotu LL
		void pop_index(int index);				//odstran� hodnotu LL na nThe pozici
		void reverse();							//prohod� v�echny ukazatele LL => obr�t� LL
	



		/* - - - - - - - - private metody - - - - - - - - - - */
	private:
		void printList_normal(node* t);			//vyp�e bez indexu norm�ln� 
		void printList_reversed(node* t);		//vyp�e bez indexu pozp�tku 
		void printList_index();			//vyp�e s indexem norm�ln�	
		
	};
}


