#pragma once

namespace ds {

class Stack
{
private:
	size_t m_maxSize;
	size_t m_currentSize;
	int* m_stack;

public:
	Stack();
	Stack(size_t maxSize);
	~Stack();

	int pop();
	void push(int value);
	void clear();

	size_t getMaxSize() const;
	size_t getCurrentSize() const;
	void printStack() const;

private:
	void reallocateOnHeap();
};
}


