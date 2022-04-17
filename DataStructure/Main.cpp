#include "pch.h"
#include "LL.h"

#define P(x) std::cout << x << std::endl;

int main(void)
{	
	ds::LinkedList a;
	long long usr;
	int log;
	std::cout << "Zadejte lib cislo: ";
	std::cin >> usr;

	for (long long i = 0; i < usr; i++)
		a.push_end(i+1);
while (true) {
	system("cls");
	log = 0;
	P("Zvolte moznost co chcete udelat: ");
	P("1. vypsat pole dlouze");
	P("2. vypsat pole");
	P("3. otocit pole");
	P("4. zjistit velikost pole");
	P("5. konec");
	std::cout << ">>> ";
	std::cin >> log;

		switch (log)
		{
		case 1:
			a.printList(ds::printStyle::INDEX);
			system("pause>nul");
			break;
		case 2:
			a.printList();
			system("pause>nul");
			break;
		case 3:
			a.reverse();
			break;
		case 4:
			P(a.getSize());
			system("pause>nul");
			break;
		case 5:
			return 0;
		}
	}
}