#include <iostream>
#include <vector>
#include <algorithm>

// 조건자(predicator) : 반환 타입이 bool 인 함수

// 아래와 같은 함수를 흔히 "단항 조건자" 라는 용어로 부릅니다.
bool foo(int n)
{
	return n % 3 == 0;
}

int main()
{
	std::vector<int> v = { 1,9,3,4,5,6,7,8,9,10 };

	// 주어진 구간에서 3을 찾고 싶다.
	auto ret1 = std::find(v.begin(), v.end(), 3);


	// 주어진 구간에서 "3의 배수"를 찾고 싶다.
	// 
	// std::find    : 값   검색. 3번째 인자로 "값" 전달
	// std::find_if : 조건 검색. 3번째 인자로 "함수" 전달

	auto ret2 = std::find_if(v.begin(), v.end(), foo );

}