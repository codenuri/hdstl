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

	// std::reverse : 처음요소과 마지막 요소의 swap. 즉, 각 요소를 swap 해서 구현
	//				  요소의 크기가 크다면 오버헤드가 있을수 있다.
	// 
	// list::reverse 멤버 함수 : Node 의 next/prev 포인터를 swap 하는 원리
	//						sizeof(포인터) 크기의 swap 으로 구현.
}
