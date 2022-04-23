#include "pch.h"
#include "LinkedList.h"

#define P(x) std::cout << x << std::endl;

int main(void)
{
	ds::LinkedList a;

	for (size_t i = 0; i < 20; i++)
		 a.push_index(i, i+1);
	
	for (size_t i = 15; i < 20; i++)
		a.push_index(i, 0);
	
	a.printList(); 
	std::cout << a.getSize() << std::endl;

	system("pause>nul");
}