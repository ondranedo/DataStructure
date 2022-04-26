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