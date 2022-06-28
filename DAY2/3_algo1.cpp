#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ranges>

// 알고리즘 
// 일반적인 용어   : "문제를 해결하는 방법" 이라는 의미
// C++ STL 에서는 : 멤버 함수가 아닌 "일반 함수 템플릿" 를 의미..
//					=> 다양한 문제를 해결하는 함수 라는 의미로 붙인 용어

// 100여개의 알고리즘 이 있고, 아래의 헤더들이 필요
// <algorithm>  : 대부분의 알고리즘
// <numeric>	: 수치관련 알고리즘
// <memory>		: 메모리 관련 알고리즘

// cppreference.com 의 1번째 화면 "algorithm library" 참고


// 알고리즘 기본
int main()
{
	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };
	
	// 다음중 쉬워 보이는 것은 ?
//	auto p1 = v.find(3); // 쉬워 보이지만, 이렇게 만들면
						// 모든 종류의 컨테이너에 find 멤버 함수가 있어야 합니다.

	auto p2 = std::find( v.begin(), v.end(), 3); 
					// 이렇게 만들면 복잡해 보이지만
					// 한개의 find 로 모든 컨테이너에서 선형 검색 가능합니다.

	// 반복자 버전 말고, 컨테이너 버전은 없나요 ?
	// => C++98 시절에는 기술적인 문제로 만들수 없었습니다.
	// auto p3 = std::find(v , 3);

	// 그런데, C++20 에서 해결했습니다.(새로운 문법 도입)
	// => 그래서 컨테이너 버전이 있습니다.
	auto p3 = std::ranges::find(v , 3);

	return 0;
}



















//
