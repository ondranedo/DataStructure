#pragma once
#include "LinkedList.h"

namespace ds {
	template <class T>
	class StackArray
	{
	private:
		size_t m_maxSize;
		size_t m_currentSize;
		T* m_stack;

	public:
		StackArray();
		StackArray(size_t maxSize);
		~StackArray();

		T pop();
		T top();
		void push(T value);
		void clear();
		size_t getMaxSize() const;
		size_t getCurrentSize() const;
		void printStack() const;

	private:
		void reallocateOnHeap();
	};
	
	template <class T>
	class StackLinkedList {
		LinkedList<T> LL;

	public:
		StackLinkedList();
		~StackLinkedList();

		T pop();
		T top();
		void push(T value);
		void clear();
		size_t getCurrentSize() const;
		void printStack() const;
	};
	
}

using namespace ds;

/*StackArray*/
template <class T>
StackArray<T>::StackArray()
{
	m_currentSize = 0;
	m_maxSize = 1024;
	m_stack = new T[m_maxSize];
}

template <class T>
StackArray<T>::StackArray(size_t maxSize)
{
	m_currentSize = 0;
	m_maxSize = maxSize;
	m_stack = new T[m_maxSize];
}

template <class T>
StackArray<T>::~StackArray()
{
	delete[] m_stack;
}

template <class T>
T StackArray<T>::pop()
{
	if (m_currentSize == 0) return 0;

	T poppedVal = m_stack[m_currentSize];
	m_currentSize--;
	return poppedVal;
}

template<class T>
T StackArray<T>::top()
{
	return m_stack[m_currentSize];
}

template <class T>
void StackArray<T>::push(T value)
{
	if (m_currentSize >= m_maxSize) { reallocateOnHeap(); }
	m_stack[m_currentSize] = value;
	m_currentSize++;
}

template <class T>
void StackArray<T>::clear()
{
	m_currentSize = 0;
}

template <class T>
size_t StackArray<T>::getMaxSize() const
{
	return m_maxSize;
}

template <class T>
size_t StackArray<T>::getCurrentSize() const
{
	return m_currentSize;
}

template <class T>
void StackArray<T>::printStack() const
{
	for (size_t i = 0; i < m_currentSize; i++)
		std::cout << m_stack[i] << " ";
	std::cout << std::endl;
}

template <class T>
void StackArray<T>::reallocateOnHeap()
{
	m_maxSize *= 2;
	T* old_stack = m_stack;
	T* new_stack = new T[m_maxSize];

	for (size_t i = 0; i < m_maxSize / 2; i++)
		new_stack[i] = old_stack[i];

	delete[] old_stack;
	m_stack = new_stack;
}

/* StackLinkedList */
template <class T>
StackLinkedList<T>::StackLinkedList()
{

}
template <class T>
StackLinkedList<T>::~StackLinkedList()
{
}
template <class T>
T StackLinkedList<T>::pop()
{
	return LL.pop_first();
}
template<class T>
T StackLinkedList<T>::top()
{
	T ret = LL.pop_first();
	LL.push_front(ret);
	return ret;
}
template <class T>
void StackLinkedList<T>::push(T value)
{
	LL.push_front(value);
}
template <class T>
void StackLinkedList<T>::clear()
{
	LL.clearLinkedList();
}
template <class T>
size_t StackLinkedList<T>::getCurrentSize() const
{
	return LL.getSize();
}
template <class T>
void StackLinkedList<T>::printStack() const
{
	LL.printList();
}


