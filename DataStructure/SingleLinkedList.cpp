#include "pch.h"
#include "LinkedList.h"

using namespace ds;

/* - - - - - - tisk spojového seznamu - - - - - - */
void SingleLinkedList::printList_index()const
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
void SingleLinkedList::printList_iter() const
{
	node* tmp = head;
	unsigned long long counter;
	for (counter = 0; tmp != NULL; tmp = tmp->next, counter++)
	{ 
		std::cout << tmp->data << " ";
	}
}
void SingleLinkedList::printList_recursion(node* t) const
{
	if (t == NULL) { return; }
	std::cout << t->data << " ";
	printList_recursion(t->next);
}
void SingleLinkedList::printList(printStyle mode) const
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
void SingleLinkedList::printList() const
{
	printList(printStyle::NORMAL);
}



/* - - - - - - pøidání na spojový seznam - - - - - - */
void SingleLinkedList::push_index(int index, int data)
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
void SingleLinkedList::push_front(int data)
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
void SingleLinkedList::push_end(int data)
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
void SingleLinkedList::pop_last()
{
	if (size <= 0)return;
	size--;
	node* tmp = head;
	for (; tmp->next->next != NULL; tmp = tmp->next) {}
	tmp->next = NULL;
	delete tmp->next;
}
void SingleLinkedList::pop_first()
{
	if (size <= 0)return;
	size--;
	node* tmp = head;
	head = tmp->next;
	delete tmp;
}
void SingleLinkedList::pop_index(int index)
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
void SingleLinkedList::reverse(reverseStyle mode)
{
	switch (mode)
	{
	case reverseStyle::RECURSION:
		reverse_recursion(head);
		break;
	case reverseStyle::ITERATION:
		reverse_iter();
		break;
	}
}
void SingleLinkedList::reverse()
{
	reverse(reverseStyle::NORMAL);
}
void SingleLinkedList::reverse_recursion(node* tmp)
{
	if (tmp->next == NULL) { head = tmp; return; }
	reverse_recursion(tmp->next);
	node* q = tmp->next;
	q->next = tmp;
	tmp->next = NULL;
}
void SingleLinkedList::reverse_iter()
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
unsigned long long SingleLinkedList::getSize() const
{
	return size;
}
// vrati index na kterem nalezi hodnota
int SingleLinkedList::locate(int find) const
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
SingleLinkedList::SingleLinkedList()
{
	head = NULL;
	size = 0;
}
SingleLinkedList::~SingleLinkedList()
{
	size = 0;
	head->data = NULL;
	head->next = nullptr;
	delete head;
}