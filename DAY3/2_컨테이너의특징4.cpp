#include <set> // Red Black Tree
#include <functional>
#include <iostream>
// 107 ~ 108

// 단위 전략 디자인 ( policy base design )
// => 클래스가 사용하는 다양한 정책을 template 인자로 교체하는 기술

// 1. 컨테이너의 메모리 할당 방식을 템플릿 인자를 통해서 "사용자 정의 allocator" 
//    로 변경

// 2. set 등의 컨테이너의 요소 비교도 템플릿 인자로 교체


// STL set 의 원리는 아래와 같습니다.
/*
template<typename T,					// 저장할 타입
	     typename PR = std::less<T>,	// 요소를 비교할때 사용할함수객체
		 typename Alloc = std::allocator<T> >
class set
{ 
	// tree 에 필요한 멤버들
	Alloc ax; // 메모리 할당기
	PR    f;  // 비교에 사용할 함수 객체
public:
	void insert(const T& elem)
	{
		// 만약 2개 요소의 크기비교를 아래 처럼 직접 "<" 를 사용 했다면
		// 사용자가 요소의 비교 정책을 교체 할수 없게 됩니다.
		if (root->elem < elem)
		{
		}
		// 그래서 아래 처럼 2번째 템플릿 인자로 전달된 타입의 객체(함수객체)
		// 를 사용해서 비교 하고 있습니다.
		if (f(root->elem, elem)) // 크기 비교시 템플릿 2번째 인자로 보낸
		{						   // 객체 사용
		}
	}	
};
*/
int main()
{
//	std::set<int> s; // Red Black Tree 입니다. std::less<int> 로 요소 비교

	std::set<int, std::greater<int> > s;
					// 큰것을 왼쪽에, 작은 것은 오른쪽

	s.insert(15);
	s.insert(25);
	s.insert(5);
	s.insert(17);
	s.insert(10);

	auto p = s.begin();

	while (p != s.end())
	{
		std::cout << *p << ", ";
		++p;
	}
	std::cout << std::endl;
}