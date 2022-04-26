#include "pch.h"


using namespace ds;


ArrayStack::ArrayStack()
{
	m_currentSize = 0;
	m_maxSize = 1024;
	m_stack = new int[m_maxSize];
}

ArrayStack::ArrayStack(size_t maxSize)
{
	m_currentSize = 0;
	m_maxSize = maxSize;
	m_stack = new int[m_maxSize];
}

ArrayStack::~ArrayStack()
{
	delete[] m_stack;
}

int ArrayStack::pop()
{
	if (m_currentSize == 0) return 0;

	int poppedVal = m_stack[m_currentSize];
	m_currentSize--;
	return poppedVal;
}

void ArrayStack::push(int value)
{
	if (m_currentSize >= m_maxSize) { reallocateOnHeap(); }
	m_stack[m_currentSize] = value;
	m_currentSize++;
}

void ArrayStack::clear()
{
	m_currentSize = 0;
}

size_t ArrayStack::getMaxSize() const
{
	return m_maxSize;
}

size_t ArrayStack::getCurrentSize() const
{
	return m_currentSize;
}

void ArrayStack::printStack() const
{
	for (size_t i = 0; i < m_currentSize; i++)
		std::cout << m_stack[i] << " ";
	std::cout << std::endl;
}

void ArrayStack::reallocateOnHeap()
{
	m_maxSize *= 2;
	int* old_stack = m_stack;
	int* new_stack = new int[m_maxSize];

	for (size_t i = 0; i < m_maxSize/2; i++)
		new_stack[i] = old_stack[i];

	delete[] old_stack;
	m_stack = new_stack;
}