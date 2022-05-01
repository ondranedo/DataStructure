#include "pch.h"
#include "ds/LinkedList.h"

#define P(x) std::cout << x << std::endl;

int main()
{
	ds::LinkedList <int>a;
	for (int i = 0; i < 10; i++)
		a.pushTail(i + 1);
	a.printHead();
	P(a.search(11));
	system("pause>nul");
}