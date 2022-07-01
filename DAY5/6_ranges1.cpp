#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	for (auto e : v)
	{
		std::cout << e << std::endl;
	}

	// �� �ڵ��� ������ �Ʒ� �ڵ� �Դϴ�.

	auto p1 = v.begin();
	auto p2 = v.end();

	for (; p1 != p2; ++p1 )
	{
		auto e = *p1;

		std::cout << e << std::endl;
	}

}

