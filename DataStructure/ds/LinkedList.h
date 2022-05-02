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
		T m_null = NULL; //prazda oamet ktera se ma vracet

	public:
		//public metody
		LinkedList();
		~LinkedList();
		T popHead();
		T popTail();
		T popIndex(size_t index);
		void pushHead(T data);
		void pushTail(T data);
		void pushIndex(size_t index, T data);
		T search(size_t index) const;
		void clear();
		size_t size() const;
	};
}

#include "LinkedList.hpp"




