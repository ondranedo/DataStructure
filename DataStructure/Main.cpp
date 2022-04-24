#include "pch.h"

#define P(x) std::cout << x << std::endl;

int main(void)
{
	ds::Stack a;
	size_t size;
	std::cout << "Zadejte velikost staku: ";
	std::cin >> size;

	for (int i = 0; i < size; i++)
		a.push(i+1);
	a.printStack();
	P(a.getMaxSize());
	P(a.getCurrentSize());
	system("pause>nul");

}