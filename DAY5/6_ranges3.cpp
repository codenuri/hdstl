#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>  // C++20 ���� �߰��Ǵ� ���

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// ��ø ���
	std::ranges::take_view tv(v, 3);
	std::ranges::reverse_view rv(tv); // rv�� �ٶ󺸸� 3, 2, 1

	// �� 2���� �Ʒ� ó���ص� �˴ϴ�.

	auto rv2 = v | std::views::filter([](int n) { return n % 2 == 0; } 
		         | std::views::take(3);


	for (auto e : rv2)
	{
		std::cout << e << std::endl;
	}



}

