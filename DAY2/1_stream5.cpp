#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int> s = { 1,2,3,4,5 };
	int x[5] = {1,2,3,4,5};

	// show 를 만들어 봅시다.
	show(s);
	show(x);

	show(s.begin(), s.end());
	show(x, x+5);
}