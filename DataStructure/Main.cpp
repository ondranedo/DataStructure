#include "pch.h"
#include "LinkedList.h"

#define P(x) std::cout << x << std::endl;

int main(void)
{
	ds::LinkedList a;

	for (size_t i = 1; i < 100; i++)
		 a.push_index(i, i+1);
	
	
	a.printList();
	std::cout << a.getSize() << std::endl;

	system("pause>nul");
}