#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>  // C++20 에서 추가되는 헤더

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 중첩 허용
	std::ranges::take_view tv(v, 3);
	std::ranges::reverse_view rv(tv); // rv로 바라보면 3, 2, 1

	// 위 2줄은 아래 처럼해도 됩니다.

	auto rv2 = v | std::views::filter([](int n) { return n % 2 == 0; } 
		         | std::views::take(3);


	for (auto e : rv2)
	{
		std::cout << e << std::endl;
	}



}

