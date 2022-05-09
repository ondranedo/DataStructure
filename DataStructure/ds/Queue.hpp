#include "Queue.h"
#pragma once

template<class T>
void Queue<T>::enqueue(T data)
{
	m_LL.pushTail(data);
	return;
}

template<class T>
T Queue<T>::dequeue()
{
	return m_LL.popHead();
}

template<class T>
T Queue<T>::front() const
{
	return m_LL.search(0);
}

template<class T>
T Queue<T>::back() const
{
	return m_LL.search(m_LL.size());
}

template<class T>
void Queue<T>::clear()
{
	m_LL.clear();
	return;
}

template<class T>
bool Queue<T>::isEmpty() const
{
	if (m_LL.size() == 0) return true;
	return true;
}


