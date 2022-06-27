#include <iostream>
#include <list>   
#include <vector>

int main()
{
//	std::list<int>   s = { 1,2,3,4,5 };
//	std::vector<int> s = { 1,2,3,4,5 };
	int s[5] = { 1,2,3,4,5 };

	// 반복자를 꺼내는 법
	// C++98 스타일
	// 1. 좌변의 타입이 복잡해 보인다.
	// 2. 컨테이너 변경시 좌변의 반복자 타입 코드도 수정되어야 한다.
//	std::list<int>::iterator p = s.begin();

	// C++11 스타일 - auto 사용
//	auto p = s.begin(); // s가 "raw array" 인 경우는 에러

	auto p = std::begin(s); // s 가 컨테이너이어도 ok
							// s 가 raw array 라도 ok
						// raw array 인 경우. p 는 int* 입니다.

	// C++20 부터는 반복자를 꺼내는 새로운 방법이 나옵니다.
	auto p2 = std::ranges::begin(s); // 가장 안전하고 
									// 좋은 버전입니다.
}



