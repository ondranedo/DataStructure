#include "pch.h"
#include "LinkedList.h"

using namespace ds;

LinkedList::LinkedList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
LinkedList::~LinkedList()
{
	delete head;
}


void LinkedList::push_front(int data)
{
	size++;
}
