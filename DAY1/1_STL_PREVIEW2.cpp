// 1_STL_PREVIEW1
#include <iostream>
#include <list>		// 더블 링크드 리스트
#include <vector>

int main()
{
	std::list<int> s = { 1,2,3,4,5 }; // 생성시 초기화 가능

	s.push_back(10);
	s.push_front(20);

	std::vector<int> v = { 1,2,3,4,5 }; // 모든 요소가 연속된 메모리
	v[0] = 10; // 배열 처럼 [] 사용도 가능.
}