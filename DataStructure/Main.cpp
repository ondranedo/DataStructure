#include "pch.h"
#include "LL.h"

#define P(x) std::cout << x << std::endl;

int main(void)
{	
	ds::LinkedList ll;
	
	for (int i = 0; i < 10; i++)
		ll.push_end(i);

	ll.printList();
	ll.reverse();
	ll.printList();
	system("pause>nul");
	return 0;
}