// 3_algo4.cpp
#include <list>
#include <vector>
#include "show.h"

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// v의 모든 요소를 "뒤집어" 보세요
	// 1. vector의 멤버 함수중 "요소 뒤집기(reverse)"를 찾아라 - 없다.
	// 2. 알고리즘 std::reverse 에 보내라.
	std::reverse(v.begin(), v.end());

	show(v); // 10,9, 8,7,6,5,4,3,2,1


	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	s.reverse(); // 멤버 함수에 있다.. 알고리즘 보다 멤버함수를 사용해라.

	show(s); // 10,9, 8,7,6,5,4,3,2,1
}