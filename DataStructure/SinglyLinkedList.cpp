#include "pch.h"

using namespace ds;

/* - - - - - - tisk spojového seznamu - - - - - - */
void SinglyLinkedList::printList_index()const
{

	node* tmp = head;
	unsigned long long counter;
	std::cout << "HEAD->" << head << std::endl;
	std::cout << "INDEX\t" << "DATA\t" << "&ADDRES\t\t\t" << "->POINTING TO\t" << std::endl;

	for (counter = 0; tmp != NULL; tmp = tmp->next, counter++)
	{
		std::cout << counter + 1 << "\t" << tmp->data << "\t" << tmp << "\t" << tmp->next << "\t" << std::endl;
	}

	std::cout << "~~~~~~~~~~~" << std::endl;
}
void SinglyLinkedList::printList_iter() const
{
	node* tmp = head;
	unsigned long long counter;
	for (counter = 0; tmp != NULL; tmp = tmp->next, counter++)
	{
		std::cout << tmp->data << " ";
	}
	std::cout << std::endl;
}
void SinglyLinkedList::printList_recursion(node* t) const
{
	if (t == NULL) { return; }
	std::cout << t->data << " ";
	printList_recursion(t->next);
}
void SinglyLinkedList::printList(printStyle mode) const
{
	switch (mode)
	{
	case printStyle::ITERATION:
		printList_iter();
		break;
	case printStyle::RECURSION:
		printList_recursion(head);
		std::cout << std::endl;
		break;
	case printStyle::INDEX:
		printList_index();
		break;
	default:
		std::cout << "UNSPECIFIED VALUE" << std::endl;
		break;
	}
}
void SinglyLinkedList::printList() const
{
	printList(printStyle::NORMAL);
}



/* - - - - - - pøidání na spojový seznam - - - - - - */
void SinglyLinkedList::push_index(int index, int data)
{
	if (index <= 1) {
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
void SinglyLinkedList::push_front(int data)
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
void SinglyLinkedList::push_end(int data)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new node;
	tmp = tmp->next;
	tmp->data = data;
	tmp->next = NULL;
}

/* - - - - - - smazání ze Spojovéhop seznamu - - - - - - */
int SinglyLinkedList::pop_last()
{
	int reVal;
	if (size <= 0)return -1;
	size--;
	node* tmp = head;
	for (; tmp->next->next != NULL; tmp = tmp->next) {}
	reVal = tmp->data;
	tmp->next = NULL;
	delete tmp->next;
	return reVal;
}
int SinglyLinkedList::pop_first()
{
	int reVal;
	if (size <= 0) return -1;
	size--;
	node* tmp = head;
	reVal = head->data;
	head = tmp->next;
	delete tmp;
	return reVal;
}
int SinglyLinkedList::pop_index(int index)
{
	if (index > size) return -1;


	if (index <= 1)
	{
		return pop_first();
	}
	int reVal;
	size--;
	node* tmpl = head;

	for (int i = 1; i < index - 1; i++)
		tmpl = tmpl->next;

	node* tmpr = tmpl->next;
	tmpl->next = tmpr->next;
	reVal = tmpr->data;
	delete tmpr;
	return reVal;
}

/* - - - - - - algoritmy - - - - - - */
//* - - - - - - obrati poradi prvku - - - - - - */
void SinglyLinkedList::reverse(reverseStyle mode)
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
void SinglyLinkedList::reverse()
{
	reverse(reverseStyle::NORMAL);
}
void SinglyLinkedList::reverse_recursion(node* tmp)
{
	if (tmp->next == NULL) { head = tmp; return; }
	reverse_recursion(tmp->next);
	node* q = tmp->next;
	q->next = tmp;
	tmp->next = NULL;
}
void SinglyLinkedList::reverse_iter()
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
size_t SinglyLinkedList::getSize() const
{
	return size;
}
// vrati index na kterem nalezi hodnota
int SinglyLinkedList::locate(int find) const
{
	node* tmp = head;
	int i = 0;
	for (; tmp->data != find && tmp->next != NULL; tmp = tmp->next, i++)
	{
		if (tmp->next == NULL && tmp->data != find) return -1;
	}
	return i + 1;
}

void SinglyLinkedList::clearLinkedList()
{
	node* tmp = head;
	node* next = tmp->next;

	while (tmp->next != NULL)
	{
		delete tmp;
		tmp = next;
		next = next->next;
	}
	head = NULL;
	size = 0;
}

/* - - - - - - Konstruktory / Dekonstruktory - - - - - - */
SinglyLinkedList::SinglyLinkedList()
{
	head = NULL;
	size = 0;
}
SinglyLinkedList::~SinglyLinkedList()
{
	clearLinkedList();
}