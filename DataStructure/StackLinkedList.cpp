#pragma once
#include "pch.h"

using namespace ds;

LinkedListStack::LinkedListStack()
{
}
LinkedListStack::~LinkedListStack()
{
}

int LinkedListStack::pop()
{
	return 0;
}

void LinkedListStack::push(int value)
{
	LL.push_front(value);
}

void LinkedListStack::clear()
{
	
}

size_t LinkedListStack::getCurrentSize() const
{
	return LL.getSize();
}

void LinkedListStack::printStack() const
{
	LL.printList();
}