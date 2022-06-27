#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

// 5개의 iterator category - 53page 표
// 입력반복자 : =*p, ++
// 출력반복자 : *p=, ++ 
// -- 위2개는 멀티 패스 지원 안됩니다, 아래 3개는 멀티 패스 지원 됩니다.// 
// 전진형반복자 : =*p, ++			싱글리스트
// 양방형반복자 : =*p, ++, --		더블리스트
// 임의접근반복자 : =*p, ++, --, +, -, []  연속된 메모리와 유사한 구조

// continuous(C++17)

int main()
{
	std::forward_list<int> s1 = { 1,2,3 };
	std::list<int> s2 = { 1,2,3 };
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// find 알고리즘은 주어진 구간에서 "선형검색"을 수행합니다.
	// 1, 2번째 인자는 반복자 입니다.
	// 최소 요구 조건을 5개 카테고리중에서 선택해 보세요.
	auto p = std::find(v.begin(), v.end(), 5);
				// => 입력 반복자

	std::reverse(v.begin(), v.end());
			// => 최소 요구 조건은 ? 양방향 반복자

	std::sort(v.begin(), v.end());
			// => 퀵 소트 입니다. 최소 요구 조건은 ? 
			// => 임의 접근 반복자.. 

	// std::find 같은 "멤버가 아닌 일반 함수"를 
	// STL 에서는 "알고리즘"이라고 합니다.
	// 대부분의 알고리즘은 인자로 "반복자"를 받게 되는데.
	// 각 알고리즘이 요구하는 반복자의 종류가 미리 정의되어 있습니다.
	// std::find    : 입력반복자
	// std::reverse : 양방향반복자
	// std::sort    : 임의접근 반복자

}