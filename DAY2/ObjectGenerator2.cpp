#include <iostream>
#include <tuple>

int main()
{
	// pair :  서로 다른 타입 2개를 보관할수 있는 구조체 입니다.
	std::pair<int, double> p1(1, 3.4); // 명시적으로 타입을 전달하는 경우

	auto p2 = std::make_pair(1, 3.4);	// 함수 템플릿을 사용하는 경우
										// 타입을 전달하지 않아도 된다.

	std::tuple<int, double, char, int> t1(1, 3.4, 'A', 10);
							// 서로 다른 타입을 N개 보관 가능한 구조체

	auto t2 = std::make_tuple<int, double, char, int>(1, 3.4, 'A', 10);
	auto t3 = std::make_tuple(1, 3.4, 'A', 10); // ok. 타입 생략!

	// 그런데, C++17 부터는 아래처럼만 해도 됩니다.
	std::tuple t4(1, 3.4, 'A', 10); // ok.
}