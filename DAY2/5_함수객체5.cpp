#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n)
{
	return n % 3 == 0;
}

int main()
{
	std::vector<int> v = { 1,9,3,4,5,6,7,8,9,10 };

	// 주어진 구간에서 "3의 배수"를 찾아라!
	auto ret1 = std::find_if(v.begin(), v.end(), foo);

	// 핵심 : 아래 코드 생각 해 보세요
	int k = 0;
	std::cin >> k;

	// 주어진 구간에서 "k의 배수"를 찾아라!!
	// => ? 를 채워 보세요.. 
	auto ret2 = std::find_if(v.begin(), v.end(), ?);
}