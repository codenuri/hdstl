#include <iostream>
#include <list>
#include <vector>

template<typename T>
typename T::value_type sum(T first, T last)
{
	// value_type 은 컨테이와 반복자에 모두 있습니다.
	// std::list<int>::value_type           : list 가 저장하는 요소의 타입
	// std::list<int>::iterator::value_type : 반복자가 가리키는 요소의 타입
	// 
	// T				: 반복자 타입 ( std::list<int>::iterator )
	// T::value_type	: 반복자가 가리키는 요소의 타입
	typename T::value_type s = 0;

	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}

int main()
{
//	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	int n = sum( std::begin(s), std::end(s) );

	std::cout << n << std::endl; // 55
}