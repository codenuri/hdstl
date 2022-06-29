// 5_함수객체10
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // C++98 부터 지원되는 C++ 표준 함수 객체들
inline bool cmp1(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// std::sort 사용 하는 방법
	// 1. 비교 정책을 전달하지 않으면 오름 차순으로 정렬
	std::sort( v.begin(), v.end() );     

	// 2-1. 비교정책으로 일반 함수 사용
	std::sort(v.begin(), v.end(), cmp1); // 2개 요소 비교시 cmp1 을 사용하는데
										// cmp1 이 인라인 치환이 되지는 않습니다.
										// 즉, 수십~수백번 cmp1 이 호출됩니다.

	// 2-2. 비교 정책으로 함수 객체를 사용하는 경우
	std::less<int> f;	// 이미 C++표준(C++98) 에 많은 함수 객체가 있습니다.
						// "a < b" 를 수행하는 이항 함수객체 - 87page
	std::sort(v.begin(), v.end(), f);

	// less 를 여러번 사용한다면,, 위처럼 만들어 사용하세요..
	// 그런데, 한번만 사용하면 아래 처럼 임시객체형태로 사용하는 경우가 많습니다
	std::sort(v.begin(), v.end(), std::less<int>() );
}