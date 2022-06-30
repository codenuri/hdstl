#include <iostream>
#include "show.h"

#include <set> // Red Black Tree로 구현

int main()
{
	std::set<int> s;
//	std::set<int, std::greater<int> > s; // 이렇게 하면
								// 아래 핵심 1의 ret 타입도 변경해야 합니다.
	s.insert(20); 
	s.insert(30); 
	s.insert(15);
	s.insert(5);
	s.insert(40);

	// 핵심 1. set 은 요소의 중복을 허용하지 않습니다.
	// insert 의 반환 타입은 pair 입니다
	// 반환값 pair 의 first, second 의미도 알아 두세요
	// ret.first : 이미 존재하는 요소를 가리키는 반복자
	// ret.second : 성공/실패 여부를 담은 bool 값
	std::pair<std::set<int>::iterator, bool> ret = s.insert(15);
	auto ret = s.insert(15);

	if (ret.second == false)
	{
		std::cout << "실패" << std::endl;
		std::cout << *(ret.first) << std::endl; // 15
	}

	// 핵심 2. set 의 요소 삽입은 insert(emplace) 만 사용가능합니다.
	//        push_xxx() 계열 함수는 사용할수 없습니다.
//	s.push_back(90); // 될까요 ?? error.

	
	// 핵심 3. 
	auto p = s.begin(); 
//	*p = 30; // error. 읽기만 가능하고
			 // 쓰기는 안됩니다.


	while (p != s.end())
	{
		std::cout << *p << std::endl;
		++p; 
	}
}








