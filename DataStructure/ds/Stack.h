/**
 *	@date: y2022m05d02
 *	@autor: Ondrej Nedojedly
 */
#pragma once
#include "../pch.h"
#include "LinkedList.h"

namespace ds {
	template <class T>
	class Stack {
	private:
		ds::LinkedList<T> m_ll;

	public:
		void push(T data);
		T pop();
		T top() const;
		bool isEmpty() const;
		void clear();
	};
}

#include "Stack.hpp"