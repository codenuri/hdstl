#include <vector>

template<typename T>
class list
{
public:
	list() {}
	list(int sz) {}
	list(int sz, T value) {}

	template<typename C> 
	list(C& c) {}

	template<typename IT>
	list(IT first, IT last) {}
};
// class template type deduction guide 라는 문법입니다. => C++17
// 생성자모양 -> list<타입>
list(int sz)->list<int>;

template<typename C>
list(C& c)->list< typename C::value_type >;

template<typename IT>
list(IT first, IT last)->list<typename std::iterator_traits<IT>::value_type>;

int main()
{
	list s1(10, 3); // ok.. 생성자 인자로 T 타입 추론 가능, C++17부터
	list s2(10);    // 

	std::vector v = { 1,2,3 };

	list s3(v); // v와 동일한 요소로 초기화 해달라.
			    // 이코드가 되도록 만들어 봅시다.
	list s4(v.begin(), v.end());
}