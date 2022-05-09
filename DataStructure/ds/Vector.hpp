#include "Vector.h"
#pragma once

using namespace ds;


template<class T>
Vector<T>::Vector():
	m_size_max(256)
{
	m_head = new T[m_size_max];
}

template<class T>
Vector<T>::Vector(size_t init_size) :
	m_size_max(init_size)
{
	m_head = new T[m_size_max];
}

template<class T>
Vector<T>::~Vector()
{
	delete[] m_head;
}

template<class T>
void Vector<T>::add(size_t index, T data)
{
	if (index < 0) return;
	if (index >= m_size_max) reAllocate();
	*(m_head + index) = data;
}

template<class T>
T Vector<T>::get(size_t index) const
{
	return m_head[index];
}

template<class T>
size_t Vector<T>::getSize() const
{
	return m_size_max;
}

template<class T>
T& Vector<T>::operator[](size_t index)
{
	if (index > m_size_max)
	{
		reAllocate();
	}

	return m_head[index];
}


template<class T>
void Vector<T>::reAllocate()
{
	m_size_max *= 2;
	T* newarr = new T[m_size_max];

	for (size_t i = 0; i < m_size_max / 2; i++)
		newarr[i] = m_head[i];

	T* newptr = newarr;

	delete[] newarr;
	m_head = newptr;
}
