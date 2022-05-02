/**
 *	@date: y2022m05d02
 *	@autor: Ondrej Nedojedly
 */
#pragma once
#include "../pch.h"
#include "LinkedList.h"

namespace ds {
	template<class T>
	class Queue {
		LinkedList<T> m_LL;
	public:
		void enqueue(T data);
		T dequeue();
		T front() const;
		T back() const;
		void clear();
		bool isEmpty() const;
	};
}

#include "Queue.hpp"