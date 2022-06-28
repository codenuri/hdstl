#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

// 알고리즘은 컨테이너를 알지 못한다. - 83 page
// => std::remove() 는 자신이 어떤 컨테이너에서 요소를 제거하는지 알수 없습니다.
// => 그래서, "제거"라는 의미는 실제 메모리 제거가 아닌
// => 뒤의 요소을 앞으로 당기는 역활을 하게 됩니다.

// => 연속된 메모리를 사용하는 vector 의 입장에서는 
//    이방식은 최선의 방식 입니다.
//    절대 나쁘지 않습니다.
int main()
{
	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	auto p = std::remove(v.begin(), v.end(), 3);

	show(v);  // 1, 2, 1, 2, 1, 2, 1,    2, 3, 1

	// 실제 컨테이너를 줄이는 것은 "멤버 함수"만 할수 있습니다.
	v.erase(p, v.end());

	show(v);  // 1, 2, 1, 2, 1, 2, 1, 

	return 0;
}



















//
