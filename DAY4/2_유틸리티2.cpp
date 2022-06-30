#include <tuple>
#include <iostream>

int main()
{
	// pair : C++98. 서로 다른 타입의 객체 2개 보관
	std::pair<int, double> p1(3, 3.4);

	// pair 로 2개 이상을 보관할수도 있습니다.

	std::pair<int, std::pair<char, double>> p2(3, 
								std::pair<char, double>('A', 3.4));

	std::cout << p2.second.second << std::endl; // 3.4 나오도록 ? 채워 보세요.

	// C++98 시절에 pair 를 사용해서 위처럼 여러개를 보관하기도 했습니다.
	// 그런데, 너무 복잡하고 불편합니다.
	// 그래서 C++11 에서 tuple 이 나왔습니다.
	std::tuple<int, char, double> t3(3, 'A', 3.4);

	// 각 요소 접근은 "std::get" 을 사용합니다
	std::get<0>(t3) = 100;

	std::cout << std::get<0>(t3) << std::endl;

}

