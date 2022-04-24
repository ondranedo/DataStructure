#include "pch.h"
#include "LinkedList.h"

#define P(x) std::cout << x << std::endl;

int main(void)
{
	ds::LinkedList ll;
	ll.push_end(1);
	ll.push_end(2);
	ll.push_end(3);
	ll.push_end(4);
	ll.push_end(5);
	ll.push_end(6);
	ll.push_end(7);
	ll.push_end(8);
	ll.push_end(9);
	ll.push_end(10);
	ll.printList();

	ll.pop_last();
	ll.pop_last();
	ll.printList();

	ll.pop_index(5);
	ll.printList();

	ll.push_index(1,69);
	ll.push_index(1,69);
	ll.printList();

	P("size: " << ll.getSize());

	system("pause>nul");
}