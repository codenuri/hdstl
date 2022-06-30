#include <iostream>
#include "show.h"

template<typename T> void foo(T a) {}

int main()
{
	// pair : 서로다른 타입 2개를 보관하는 구조체
	std::pair<int, double> p1(3, 3.4);

	std::cout << p1.first  << std::endl; // 3
	std::cout << p1.second << std::endl; // 3.4


	// std::make_pair 를 사용하면 "타입 인자" 전달을 생략할수 있습니다.
	auto p2 = std::make_pair(3, 4);

	// C++17 이후 부터는 아래 처럼 직접 std::pair 를 사용해도
	// "타입 인자" 생략 가능합니다.
	std::pair p3(1, 3.4);

	std::pair p4; // error. C++17 이후라도. 타입을 추론할수 있는
					// 정보가 없으면 에러 입니다.
					// 논리적으로 맞지 않습니다.

	std::pair<int, double> p5; // 당연히 이코드는 가능합니다.	
}


