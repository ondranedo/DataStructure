#include "pch.h"
#include "LL.h"

using namespace ds;

/* - - - - - - tisk spojového seznamu - - - - - - */
void LinkedList::printList_index()
{
	node*tmp = head;
	int counter;
	std::cout << "HEAD->" << head << std::endl;
	std::cout << "INDEX\t" << "DATA\t" << "&ADDRES\t\t\t"<< "->POINTING TO\t" << std::endl;

	for (counter = 0; tmp != NULL; tmp = tmp->next, counter++)
	{
		std::cout << counter + 1 << "\t" << tmp->data << "\t" << tmp << "\t" << tmp->next << "\t" << std::endl;
	}

	std::cout << "~~~~~~~~~~~" << std::endl;
}

void LinkedList::printList_normal(node* t)
{
	if (t == NULL) { return; }
	std::cout << t->data << " ";
	printList_normal(t->next);
}
void LinkedList::printList_reversed(node* t)
{
	if (t == NULL) {return; }
	printList_reversed(t->next);
	std::cout << t->data << " ";

}

void LinkedList::printList(printStyle mode)
{
	
	if(mode ==printStyle::BLANK)
	{ 
		std::cout << "BLANK" << std::endl;
	}
	if (mode == printStyle::INDEX)
	{
		printList_index();
	}
	if (mode == printStyle::NORMAL)
	{
		printList_normal(head);
		std::cout << std::endl;
	}
	if (mode == printStyle::REVERSED)
	{
		printList_reversed(head);
		std::cout << std::endl;
	}
	
}
void LinkedList::printList()
{
	printList(printStyle::NORMAL);
}




/* - - - - - - pøidání na spojový seznam - - - - - - */
void LinkedList::push_index(int index, int data)
{
	if (index <= 1){
		push_front(data);
		return;
	}
	if (index >= size + 2) return; 
	
	size++;
	node* tmp = head;

	for (int i = 0; i < index - 2; i++) tmp = tmp->next;	

	node* add = new node;
	add->data = data;

	add->next = tmp->next;
	tmp->next = add;
}

void LinkedList::push_front(int data)
{
	size++;

	if (head == NULL)
	{
		node* tmp = new node;
		tmp->data = data;
		tmp->next = NULL;
		head = tmp;
		return;
	}

	node* tmp = new node;
	tmp->next = head;
	tmp->data = data;
	head = tmp;
}

void LinkedList::push_end(int data)
{
	size++;
	if (head == NULL)
	{
		node* tmp = new node;
		tmp->data = data;
		tmp->next = NULL;
		head = tmp;
		return;
	}
	
	node* tmp = NULL;
	for(tmp = head;tmp->next!=NULL;tmp=tmp->next){}
	tmp->next = new node;
	tmp = tmp->next;
	tmp->data = data;
	tmp->next = NULL;
}



/* - - - - - - smazání ze Spojovéhop seznamu - - - - - - */
void LinkedList::pop_last()
{
	if (size <= 0)return;
	size--;
	node* tmp = head;
	for (; tmp->next->next != NULL; tmp = tmp->next) {}
	tmp->next = NULL;
	delete tmp->next;
}

void LinkedList::pop_first()
{
	if (size <= 0)return;
	size--;
	node* tmp = head;
	head = tmp->next;
	delete tmp;
}

void LinkedList::pop_index(int index)
{
	if (index > size) return;


	if (index <= 1)
	{
		pop_first();
		return;
	}
	
	size--;
	node* tmpl = head;

	for (int i = 1; i < index - 1; i++)
		tmpl = tmpl->next;

	node* tmpr = tmpl->next;

	tmpl->next = tmpr->next;
	delete tmpr;
}




/* - - - - - - algoritmi - - - - - - */
void LinkedList::reverse()
{
	node *replace, *save, *prev;
	replace = head;
	save = head;
	prev = NULL;
	while (replace != NULL)
	{
		save = replace->next;
		replace->next = prev;
		prev = replace;
		replace = save;
	}
	head = prev;
}


/* - - - - - - funkce návratovách hodnot - - - - - - */
int LinkedList::getSize()
{
	return size;
}


/* - - - - - - Konstruktory / Dekonstruktory - - - - - -*/
LinkedList::LinkedList()
{
	head = NULL;
	size = 0;
}

LinkedList::~LinkedList()
{
	delete head;
}