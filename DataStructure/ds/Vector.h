#pragma once

namespace ds {

	template<class T>
	class Vector
	{
		T* m_head = nullptr;
		size_t m_size_max;

	public:
		Vector();
		Vector(size_t init_size);
		~Vector();
		void add(size_t index, T value);
		T get(size_t index) const;
		size_t getSize() const;

		T& operator[](size_t index);
		

	private:
		void reAllocate();
	};
}

#include "Vector.hpp"
