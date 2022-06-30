#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <algorithm>

int main()
{
	std::vector<int> c = { 1,2,3,4,5,6,7,8,9,10 };

	auto ret = std::find(c.begin(), c.end(), 6);

	// ret 는 6을 가리키는 반복자 입니다.
	// 그런데, ret 가 몇번째 요소인지 알수 있을까요 ?

	std::cout << ret - c.begin() << std::endl;
}

