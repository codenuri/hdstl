// 유틸리티2-1
#include <tuple>
#include <list>
#include <iostream>

// tuple vs struct
// 함수에서 사각형을 반환하고 싶다.
// => 사각형이 명확 합니다. "타입 설계"가 좋지 않을까요 ?
struct Rect
{
};
Rect f1() { Rect r; return r; }

// 함수에서 임의의 값을 3개 반환하려고 합니다.(연관성 없는..)
std::tuple<int, int, int> f2()
{
	return std::make_tuple<int, int, int>(1, 2, 3);
}

int main()
{
	std::list<std::tuple<int, double>> s;
	s.push_back(std::make_tuple(1, 1.1));
	s.push_back(std::make_tuple(2, 2.2));
	s.push_back(std::make_tuple(3, 3.3));

	auto p = s.begin(); 
	
	// 반복자는 "요소를 가리키는 포인터" 라고 생각하세요. 즉
	// p = std::tuple<int, double>*
	// *p = std::tuple<int, double>
	int n = std::get<0>(*p); // 1
	double d = std::get<1>(*p); // 1.1

}