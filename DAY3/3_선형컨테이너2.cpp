
#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
	// 1. 생성
	std::vector<int> v1;		// 초기 크기는 없다.
	std::vector<int> v2(10);	// 10개를 0으로 초기화
	std::vector<int> v3(10, 3);	// 10개를 3으로 초기화
	std::vector<int> v4(v3);	// v3와 동일하게..

	std::vector<int> v5 = { 1,2,3 }; // 3개를 1, 2, 3으로 초기화
//	std::vector<int> v5 { 1,2,3 };	 // 이 코드와 위 코드는 동일합니다.

	// 아래 2개 차이점 꼭 기억하세요
	std::vector<int> v6( 10, 3 ); // 10개를 3으로 초기화
	std::vector<int> v7{ 10, 3 }; // 2개를 "10, 3"으로 초기화

	std::cout << v6.size() << std::endl; // 10
	std::cout << v7.size() << std::endl; // 2

	// 위의 모든 코드는 list, deque 도 동일합니다.

	// 2. 삽입, 




	// 3. 접근
	
	// 4. 요소 변경

}