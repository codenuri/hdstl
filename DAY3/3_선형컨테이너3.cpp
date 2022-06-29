#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

// capacity 개념 - vector 에만 있는 개념입니다.

int main()
{
	std::vector<int> v(10, 0);

	v.resize(7); // 어떻게 구현했을까요 ?

	std::cout << v.size()     << std::endl; // 7
	std::cout << v.capacity() << std::endl; // 10(메모리 사용량)


	v.push_back(3); // 끝에 한개(3) 추가
					// 현재 상태가 capacity > size 이므로
					// 이 연산은 "not expensive" 합니다.

	std::cout << v.size() << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 10

	v.shrink_to_fit(); // 여분의 메모리는 필요없다.
						// 8개 메모리 재할당해서 버퍼 복사후 사용

	std::cout << v.size() << std::endl;     // 8
	std::cout << v.capacity() << std::endl; // 8


	v.push_back(3); // 끝에 한개 추가
					// 현재 상황은 capacity == size 입니다.
					// 즉, 여유 공간이 없으므로 메모리 재할당 필요
					// 이 연산은 "expensive" 합니다.

	std::cout << v.size() << std::endl;     // 9
	std::cout << v.capacity() << std::endl; // 12(vc++, 기존 메모리 크기 1.5배)
											// 16(g++,  기존 메모리 크기 2배)

	std::vector<int> v2; // size = 0, capacity = 0
//	v2.resize(20);		// size = 20, capacity = 20
	v2.reserve(20);		// size = 0,  capacity = 20

	v2.push_back(1); // 20개가 들어오는 동안은 메모리 재할당 없으므로 
					 // 빠르게 동작합니다.
}
// 파이썬 에서.. 리스트는 C++의 vector 입니다.
// s = [1,2,3] // 실제메모리는 3개 가아닌 4개 할당합니다.
// s.append(4) // 여유공간이 있으므로 메모리 재할당 없으므로 빠릅니다.
// s.append(5) // 5개가 아니라 8개의 메모리로 재할당 됩니다.






