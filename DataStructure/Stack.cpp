#include "pch.h"


using namespace ds;


Stack::Stack()
{
	m_currentSize = 0;
	m_maxSize = 1024;
	m_stack = new int[m_maxSize];
}

Stack::Stack(size_t maxSize)
{
	m_currentSize = 0;
	m_maxSize = maxSize;
	m_stack = new int[m_maxSize];
}

Stack::~Stack()
{
	delete[] m_stack;
}

int Stack::pop()
{
	if (m_currentSize == 0) return 0;

	int poppedVal = m_stack[m_currentSize];
	m_currentSize--;
	return poppedVal;
}

void Stack::push(int value)
{
	if (m_currentSize >= m_maxSize) { reallocateOnHeap(); }
	m_stack[m_currentSize] = value;
	m_currentSize++;
}

void Stack::clear()
{
	m_currentSize = 0;
}

size_t Stack::getMaxSize() const
{
	return m_maxSize;
}

size_t Stack::getCurrentSize() const
{
	return m_currentSize;
}

void Stack::printStack() const
{
	for (size_t i = 0; i < m_currentSize; i++)
		std::cout << m_stack[i] << " ";
	std::cout << std::endl;
}

void Stack::reallocateOnHeap()
{
	m_maxSize *= 2;
	int* old_stack = m_stack;
	int* new_stack = new int[m_maxSize];

	for (size_t i = 0; i < m_maxSize/2; i++)
		new_stack[i] = old_stack[i];

	delete[] old_stack;
	m_stack = new_stack;
}