#pragma once
#include "LinkedList.h"

namespace ds {
	
	class  __vStack {
	public:
		//odstran� horn� prvek stacku
		virtual int pop() = 0;

		//p�id� na vrch stacku nov� prvek
		virtual void push(int value) = 0;
		
		//sma�e cel� stack
		virtual void clear() = 0;

		//zjist� akut�ln� velikost stacku
		virtual size_t getCurrentSize() const = 0;

		//vypise cely stack
		virtual void printStack() const = 0;
	};
	
	//t��da pro stack z dynamick�ho pole
	class ArrayStack :public __vStack
{
private:
	size_t m_maxSize;
	size_t m_currentSize;
	int* m_stack;

public:
	ArrayStack();
	ArrayStack(size_t maxSize);
	~ArrayStack();

	int pop();
	void push(int value);
	void clear();
	size_t getMaxSize() const;
	size_t getCurrentSize() const;
	void printStack() const;

private:
	void reallocateOnHeap();
};

	class LinkedListStack: public __vStack {
	private:
		SinglyLinkedList LL;

	public:
		LinkedListStack();
		~LinkedListStack();

		int pop();
		void push(int value);
		void clear();
		size_t getCurrentSize() const;
		void printStack() const;
	};
}


