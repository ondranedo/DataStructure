#include "pch.h"
#include "LL.h"

using namespace ds;

/* - - - - - - tisk spojového seznamu - - - - - - */
void LinkedList::printList_index()const
{

	node*tmp = head;
	unsigned long long counter;
	std::cout << "HEAD->" << head << std::endl;
	std::cout << "INDEX\t" << "DATA\t" << "&ADDRES\t\t\t"<< "->POINTING TO\t" << std::endl;

	for (counter = 0; tmp != NULL; tmp = tmp->next, counter++)
	{
		std::cout << counter + 1 << "\t" << tmp->data << "\t" << tmp << "\t" << tmp->next << "\t" << std::endl;
	}

	std::cout << "~~~~~~~~~~~" << std::endl;
}

void LinkedList::printList_iter() const
{
	node* tmp = head;
	unsigned long long counter;
	for (counter = 0; tmp != NULL; tmp = tmp->next, counter++)
	{ 
		std::cout << tmp->data << " ";
	}
}

void LinkedList::printList_recursion(node* t) const
{
	if (t == NULL) { return; }
	std::cout << t->data << " ";
	printList_recursion(t->next);
}

void LinkedList::printList(printStyle mode) const
{
	switch (mode)
	{
	case printStyle::ITERATION:
		printList_iter();
		break;
	case printStyle::RECURSION:
		printList_recursion(head);
		break;
	case printStyle::INDEX:
		printList_index();
		break;
	default:
		std::cout << "UNSPECIFIED VALUE" << std::endl;
		break;
	}
}
void LinkedList::printList() const
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
	
	node* tmp = head;
	while(tmp->next!=NULL)
		tmp = tmp->next;
	
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

/* - - - - - - algoritmy - - - - - - */
//* - - - - - - obrati poradi prvku - - - - - - */
void LinkedList::reverse(sortStyle mode)
{
	switch (mode)
	{
	case sortStyle::RECURSION:
		reverse_recursion(head);
		break;
	case sortStyle::ITERATION:
		reverse_iter();
		break;
	}
}
void LinkedList::reverse()
{
	reverse(sortStyle::NORMAL);
}

void LinkedList::reverse_recursion(node* tmp)
{
	if (tmp->next == NULL) { head = tmp; return; }
	reverse_recursion(tmp->next);
	node* q = tmp->next;
	q->next = tmp;
	tmp->next = NULL;
}

void ds::LinkedList::reverse_iter()
{
	node* prev, * save, * replace;
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
unsigned long long LinkedList::getSize() const
{
	return size;
}

// vrati index na kterem nalezi hodnota
int ds::LinkedList::locate(int find) const
{
	node* tmp = head;
	int i = 0;
	for (; tmp->data != find && tmp->next != NULL; tmp = tmp->next, i++)
	{
		if (tmp->next == NULL && tmp->data != find) return -1;
	}
	return i + 1;
}

/* - - - - - - Konstruktory / Dekonstruktory - - - - - - */
LinkedList::LinkedList()
{
	head = NULL;
	size = 0;
}

LinkedList::~LinkedList()
{
	size = 0;
	head->data = NULL;
	head->next = nullptr;
	delete head;
}