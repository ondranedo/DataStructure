#pragma once
#include "pch.h"
#include "Stack.h"

using namespace ds;

LinkedListStack::LinkedListStack()
{
}
LinkedListStack::~LinkedListStack()
{
}

int LinkedListStack::pop()
{
	return LL.pop_first();
}

void LinkedListStack::push(int value)
{
	LL.push_front(value);
}

void LinkedListStack::clear()
{
	LL.clearLinkedList();
}

size_t LinkedListStack::getCurrentSize() const
{
	return LL.getSize();
}

void LinkedListStack::printStack() const
{
	LL.printList();
}