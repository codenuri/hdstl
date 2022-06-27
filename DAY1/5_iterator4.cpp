#include <iostream>
#include <list>   
#include <vector>

// 반복자 무효화
int main()
{
//	std::vector<int> v = { 1,2,3,4,5 };
	std::list<int>   v = { 1,2,3,4,5 };
	
	auto p = std::begin(v); // v.begin()

	std::cout << *p << std::endl; // 1


	v.resize(10); // vector의 크기 변경
					// 내부 버퍼 메모리가 재할당됩니다.
					// 이전에 꺼낸 모든 반복자는 
					// "무효화(invalidate)" 됩니다. 
					// 단, list 라면 반복자가 무효화 되지 않습니다.

	std::cout << *p << std::endl; // ????
}
// cppreference.com 에서 "std::vector" 검색 해보세요.


