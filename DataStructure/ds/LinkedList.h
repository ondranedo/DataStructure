/** 
 *	@date: y2022m05d01
 *	@autor: Ondrej Nedojedly
 */
#pragma once
#include "../pch.h"

namespace ds {
	template <class T>
	class LinkedList {

		// node
		struct node {
			T data;
			node* prev;
			node* next;
		};

		//privatni parametry classy
		size_t m_size;
		node* m_head;
		node* m_tail;

	public:
		//public metody
		LinkedList();
		~LinkedList();
		T popHead();
		T popTail();
		T popIndex(size_t index);
		bool pushHead(T data);
		bool pushTail(T data);
		bool pushIndex(size_t index, T data);
		T search(size_t index) const;
		bool clear();
		size_t size() const;
		void printHead() const;
		void printTail() const;
	};
}

#include "LinkedList.hpp"




