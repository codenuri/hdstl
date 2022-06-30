#include <tuple>
#include <iostream>

int main()
{
	// pair : C++98. 서로 다른 타입의 객체 2개 보관
	std::pair<int, double> p1(3, 3.4);

	// pair 로 2개 이상을 보관할수도 있습니다.

	std::pair<int, std::pair<char, double>> p2(3, 
								std::pair<char, double>('A', 3.4));

	std::cout << ? << std::endl; // 3.4 나오도록 ? 채워 보세요.
}