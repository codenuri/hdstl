#include <iostream>
#include "show.h"

#include <set> // Red Black Tree로 구현

int main()
{
	std::set<int> s;

	s.insert(20); 
	s.insert(30); 
	s.insert(15);
	s.insert(5);
	s.insert(40);

	// 핵심 1. set 은 요소의 중복을 허용하지 않습니다.
	// insert 의 반환 타입은 pair 입니다
	std::pair<std::set<int>::iterator, bool> ret = s.insert(15);

	if (ret.second == false)
	{
		std::cout << "실패" << std::endl;
		std::cout << *(ret.first) << std::endl; // 15
	}



	auto p = s.begin();.

	while (p != s.end())
	{
		std::cout << *p << std::endl;
		++p; 
	}
}








