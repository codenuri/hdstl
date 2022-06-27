#include <iostream>
#include <vector>
#include <list>

/*
void print_first_element(std::vector<int>& v)
{
	int n = v.front();

	std::cout << n << std::endl;
}
*/

/*
template<typename T>
void print_first_element(std::vector<T>& v)
{
	T n = v.front();

	std::cout << n << std::endl;
}
*/
template<typename T>
void print_first_element(T& v)
{
	// T			 : std::list<double>
	// T::value_type : std::list<double>::value_type => double
	typename T::value_type n = v.front();

	// C++11 이후에는 아래처럼 auto 로 하면 편리합니다.
	auto n1 = v.front();

	std::cout << n << std::endl;
}


int main()
{
//	std::vector<int>    v = { 1,2,3,4,5,6,7,8,9,10 };
//	std::vector<double> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<double>   v = { 1,2,3,4,5,6,7,8,9,10 };

	print_first_element(v);
}

// 템플릿 기반의 컨테이너는 자신이 저장하는 타입이 있습니다.
// 그 타입을 알고 싶을때가 있습니다. - 위에 있는 print_first_element

// 그래서 list 를 만들때 아래처럼 만들었습니다.
template<typename T> class list
{
public:
//	typedef T value_type; // C++11이전 스타일
	using value_type = T; // C++11 이후 코딩 스타일
};

list<int> s = { 1,2,3 };
list<int>::value_type n = s.front(); // n의 타입을 생각해 보세요




