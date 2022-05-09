#include "pch.h"
#include "ds/Queue.h"
#include "ds/LinkedList.h"
#include "ds/Stack.h"
#include "ds/Vector.h"

#define NEWL true
#pragma region NEWL
#if NEWL == true
#define P(x) std::cout << x << std::endl;
#else
#define P(x) std::cout << x;
#endif //!NEWL
#pragma endregion

#define N 700

int main()
{
	ds::Vector <int> a;
	for (int i = 0; i < N; i++)
		a[i] = 0;

	P("Size: " << a.getSize());

	system("pause");
}