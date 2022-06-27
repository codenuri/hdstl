#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// std::advance() 의 원리를 생각해 봅시다.
/*
// 1. 5개의 반복자 카테고리를 타입화 합니다.
// => 아무 멤버도 없는 "empty class" 이지만
// => 하나의 독립된 타입입니다. 
// => 함수 오버로딩등의 인자로 사용가능합니다.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

// 2. 각 컨테이너의 반복자를 설계 할때
//    자신이 어느 카테고리 인지 "약속된 방법"으로 외부에 알려야 합니다.
template<typename T> class vector_iterator
{
public:
	// "iterator_category" 라는 이름으로 외부에 알리기로 약속됨.
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	// "iterator_category" 라는 이름으로 외부에 알리기로 약속됨.
	using iterator_category = bidirectional_iterator_tag;
};
*/
// enum으로 구분 안하는 이유가 있을까요? => 아래 코드 생각해 보세요
// 
// typename에서 알려주셨던 "value_type" 도 
// "iterator_category" 처럼 약속된 표현인것인가요? => 정확 합니다.!!

//----------------------
// 이제 advance 를 카테고리 별로 제공
template<typename T>
void advance_imp(T& p, int sz, std::random_access_iterator_tag)
{
	p = p + sz;
	std::cout << "random 버전" << std::endl;
}
template<typename T>
void advance_imp(T& p, int sz, std::input_iterator_tag)
{
	while (sz--)
		++p;	
	std::cout << "random 아닌 버전" << std::endl;
}
template<typename T>
void advance(T& p, int sz) // sz > 0 일때만 고려하겠습니다.
{
	// 여기서는 반복자의 종류에 따라 위에 있는 함수를 호출합니다.
	// 반복자 T의 종류는 T 안에 약속된 형태(iterator_category) 로 
	// 조사합니다
	// T::iterator_category : 5개 종류의 타입중 한개 입니다.

	// "Tag Dispatching" 이라고 불리는 "정말 유명한 기술" 입니다.
	advance_imp(p, sz, typename T::iterator_category() );
}


int main()
{
	//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = s.begin();

	advance(p, 5); 

	std::cout << *p << std::endl;
}