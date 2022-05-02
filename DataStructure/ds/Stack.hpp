#include "Stack.h"
#pragma once

using namespace ds;

template<class T>
bool Stack<T>::push(T data)
{
	return m_ll.pushHead(data);
}

template<class T>
T Stack<T>::pop()
{
	return m_ll.popHead();
}

template<class T>
T Stack<T>::top() const
{
	return m_ll.search(0);
}

template<class T>
bool Stack<T>::isEmpty() const 
{
	if (m_ll.size() == 0)
		return true;
	return false;
}

template<class T>
bool Stack<T>::clear()
{
	return m_ll.clear();
}