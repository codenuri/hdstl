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
	// 핵심 1. 각 컨테이너의 반복자가 어느 카테고리인지 반드시 알아야 합니다.
	std::forward_list<int> s1 = { 1,2,3 };	// 전진형반복자 : ++
	std::list<int> s2 = { 1,2,3 };			// 양방형반복자 : ++, --
	std::vector<int> v = { 1,2,3,4,5}; // 임의접근반복자 : ++, --, +,-,[]
	
	// 이제 아래 코드들을 생각해 보세요
	// 핵심 2. 각 알고리즘은 인자로 받는 반복자의 카테고리가 정해져 있습니다.
	std::reverse(s1.begin(), s1.end()); // error. 싱글리스트 반복자는
										// 전진형, -- 연산 안됨
	std::reverse(s2.begin(), s2.end()); // ok

//	std::sort(v.begin(),  v.end());
//	std::sort(s1.begin(), s1.end());
//	std::sort(s2.begin(), s2.end());

}