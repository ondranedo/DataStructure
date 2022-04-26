#pragma once

/*
 *	autor: Ond�ej Nedojedl�
 *	datum: y2022m04d15 (prvni upravy - git init commit)
 */

namespace ds
{

	/// t��dy
	/*
		Spojov� seznam obsahuj�c� data typu 'int'.
		Adresu na dalsi node, pomale pridavani na konec,
		asymptotick� slo�itost pro funkci push_end(), pro ohrani�eni shora je N,
		N(= po�et prvk� spojopv�ho seznamu)
		av�ak men�� jedna node, na velikost jednoho ukazatele,
		=> v�hodn�j�� pro men�� payload(=data krom� ukazatelu na dal�i node)
		node(= jeden prvek soub�zn� pam�ti...)
	*/
	class SinglyLinkedList
	{
		/*  - - - - - -private primitivn� datov� struktury - - - - - - */
		/*
		 *	struktura kde jedna ��st pam�ti p�edstavuje
		 *	jeden tzv. "node", co� je jeden prvek
		 *	spojov�ho seznamu
		 */
		struct node
		{
			int data;
			node *next;
		};

		/// typy v�pisu na obrazovku
		// typy form�t vypisu
		enum class printStyle : int
		{
			INDEX,				// indexovan� v�pis
			ITERATION,			// normlani vypis iteraci
			RECURSION,			// normalni vypis rekurzi
			NORMAL = ITERATION, // norm�ln� v�pis
		};

		// typy a vypisu se�azeni
		enum class reverseStyle
		{
			ITERATION,			// serazeni pole iteraci
			RECURSION,			// serazeni pole rekurzi
			NORMAL = ITERATION, // normalni serazeni
		};

		/* - - - - - - private prom�nn� - - - - - - */
		size_t size; // d�lka L
		node *head;				 // head linkedlist

		/* - - - - - - public metody - - - - - - */
	public:
		SinglyLinkedList();
		~SinglyLinkedList();

		void printList(printStyle mode) const; // vyp�e LL dle zvoleneho m�du
		void printList() const;				   // vyp�e LL standartn� STANDARD
		void push_end(int data);			   // vlo�� na konec LL hodnotu
		void push_front(int data);			   // vlo�� na za��tek LL hodnotu
		void push_index(int index, int data);  // vlo�� na nThou pozici LL hodnotu
		size_t getSize() const;	   // vr�t� velikost (po�et prvk�) LL
		int pop_last();					   // odstran� posledn� hodnotu LL
		int pop_first();					   // odstran� prvn� hodnotu LL
		int pop_index(int index);			   // odstran� hodnotu LL na nThe pozici
		void reverse(reverseStyle mode);	   // prohodi v�echny ukazatele LL => obr�t� LL
		void reverse();						   // prohodi v�echny ukazatele LL => obr�t� LL - NORMAL
		int locate(int find) const;			   // vyhled� v LL hodnotu a vrati index
		void  clearLinkedList();				   //smaye celz stack

		/* - - - - - -private metody - - - - - - */
	private:
		void printList_iter() const;			 // vyp�e bez indexu iteraci
		void printList_index() const;			 // vyp�e s indexem norm�ln�
		void printList_recursion(node *t) const; // vyp�e bez indexu rekurzivne
		void reverse_recursion(node *tmp);		 // obr�t� LL pres rekurzy
		void reverse_iter();					 // obr�t� LL pres iteraci
	};

	/*
		Spojov� seznam obsahuj�c� data typu 'int'.
		Adresu na dalsi node, a node p�edchoz�,
		asymptotick� slo�itost pro funkci push_end(), pro ohrani�eni shora je konstanta 1,
		av�ak v�t�� jedna node o jeden ukazatel
		[u 64b arch. pointer = 8B; u 32b arch. pointer = 4B]
		=> v�hodn�j�� u vy��� velikost payloadu(=data krom� ukazatelu na dal�i node)
		node(= jeden prvek soub�zn� pam�ti obsahuj�c� 2*node poniter a payload)
	*/
	class LinkedList
	{
	private:
		/* - - - - - - dal�� prvky - - - - - - */
		struct node
		{
			int data;
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
		void push_front(int data);

		// p�id� hodnotu na konec
		void push_end(int data);

		// p�id� hodnotu na ur�it� index
		void push_index(size_t index, int data);

		// sma�e prvn� hodnotu
		int pop_first();

		// sma�e posledn� hodnotu
		int pop_last();

		// sma�e hodnotu z ur�it�ho indexu
		int pop_index(size_t index);

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
