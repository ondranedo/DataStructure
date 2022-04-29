#include "pch.h"
#include "Stack.h"
#include "LinkedList.h"

#define P(x) std::cout << x << std::endl;

int main()
{
	const char* bracketso = "<{[(";
	const char* bracketsc = ">}])";
	size_t nofBrackets = strlen(bracketso);
	const char* expre = "{[]<()>}{}";
	size_t expreSize = strlen(expre);
	bool possible = true;


	ds::StackLinkedList <char> buffer;

	for (size_t i = 0; i < expreSize; i++)
	{	

	}

	P(possible);

	system("pause>nul");
}