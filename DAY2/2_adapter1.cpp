#include <iostream>
#include <list>
#include <algorithm>
#include <iterator> // std::advance() 

// 73 page
int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10};

	auto p1 = s.begin();
	auto p2 = s.end();

	std::advance(p1, 5);

	// reverse_iterator : ++, -- 가 거꾸로 동작하는 반복자
	// std::reverse_iterator< 반복자타입 > p3( 반복자 );
//	std::reverse_iterator< std::list<int>::iterator > p3(p1);

	// 위처럼 "reverse_iterator" 의 객체를 직접 생성하면 복잡해 보입니다.
	// 함수 템플릿의 도움을 받으면 간단히 만들수 있습니다.
	
	auto p3 = std::make_reverse_iterator(p1);
					// p1 보다 한개 앞을 가리키는 반복자
	std::cout << *p1 << std::endl; // 6
	std::cout << *p3 << std::endl; // 5

	++p3; // 거꾸로 이동합니다.
	std::cout << *p3 << std::endl; // 4
}
