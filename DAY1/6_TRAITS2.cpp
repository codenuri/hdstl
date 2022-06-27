#include <iostream>
#include <list>
#include <vector>

// C++에서 반복자 정의 : 반복자 처럼 동작하는 모든 것은 반복자 이다.
//					  => ++로 이동가능하고, *로 요소 접근이 가능한 모든것!

// 반복자의 2가지 형태
// 1. raw pointer
// 2. 클래스 문법으로 만들어진 형태(우리가 만든 slist_iterator 처럼)

// 그런데, 객체형 반복자 안에는 "value_type" 이 있지만
// raw pointer 에는 "value_type"이 없다. 

// 위 2개의 차이점때문에 생기는 문제를 해결하는 도구..
// => std::iterator_traits

template<typename T> struct iterator_traits
{
	using value_type = typename T::value_type;
};

// T = raw pointer 인 경우는 구현을 변경하기 위해 부분 특수화
template<typename T> struct iterator_traits<T*>
{
	using value_type = T;
};


template<typename T>
//typename T::value_type sum(T first, T last)
typename iterator_traits<T>::value_type sum(T first, T last)
{
//	typename T::value_type s = 0;

	typename iterator_traits<T>::value_type s = 0;

	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}
int main()
{
	// std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	// std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	int s[10] = {1,2,3,4,5,6,7,8,9,10};

	int n = sum(std::begin(s), std::end(s)); // 이 코드와
//	int n = sum(s,			   s+10);		 // 이 코드는 결국 동일합니다.

	std::cout << n << std::endl; // 55
}