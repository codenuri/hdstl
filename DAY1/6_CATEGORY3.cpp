#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = std::begin(s);

	// 반복자 p를 5칸 전진하고 싶다. 최선의 코드는 ???
//	p = p + 5;		// 임의 접근 반복자만 가능한 코드
					// list 의 반복자라면 error
//	++p; ++p; ++p; ++p; ++p; // 모든 반복자는 ++은 된다.
							 // 모든 컨테이너에 사용가능
							 // 하지만, p가 임의접근이면 느리다.!!

	std::advance(p, 5); // 최선의 코드

	sdt::cout << *p << std::endl;
}