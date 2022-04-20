#include "pch.h"
#include "LL.h"

#define P(x) std::cout << x << std::endl;

int main(void)
{

	ds::LinkedList a;

	for (int i = 0; i < 100000000; i++)
		a.push_front(i + 1);
	a.reverse();
	system("pause>nul");
		
}