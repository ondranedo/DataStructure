#include "pch.h"
#include "LL.h"

#define P(x) std::cout << x << std::endl;

int main(void)
{	
	ds::LinkedList l1;

	for (int i = 0; i < 10; i++)
		l1.push_end(i);

	l1.printList(ds::printStyle::INDEX);
	l1.printList();//ds::printStyle::REVERSED);

	system("pause>nul");
	return 0;
}