#include <iostream>
#include <vector>
#include <list>

template<typename Container>
void show( const Container& c  )
{
	// 컨테이너의 요소 출력은 range-for 가 편리합니다.
	// range-for 는 배열도 지원 합니다.
//	for (auto  e : c)	// c의 각 요소를 "e에 복사" 해서 사용하겠다는것
//	for (auto& e : c)	// c의 각 요소를 참조로 가리키겠다는것
	for (const auto& e : c)
		std::cout << e << ", ";

	std::cout << std::endl;
}

// 반복자 버전의 show
template<typename Iter>
void show(Iter first, Iter last)
{
	// typename Iter::value_type : Iter 타입이 포인터라면 에러
	// typename std::iterator_traits<Iter>::value_type : 포인터도 가능
	std::ostream_iterator< typename std::iterator_traits<Iter>::value_type > p(std::cout, ", ");

	std::copy(first, last, p);

	std::cout << std::endl;
}

int main()
{
	std::list<int> s = { 1,2,3,4,5 };
	int x[5] = {1,2,3,4,5};

	// show 를 만들어 봅시다.
	show(s);
	show(x);


	show(s.begin(), s.end());
	show(x, x+5);
}