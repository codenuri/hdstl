
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
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
//	v5.push_front(10); // 전방 삽입, 단, vector 만 안됨
					   // => 연속된 메모리의 앞쪽에 넣는 것은 너무 느리기 때문에
						//   사용하지 말라는 의도.
	v5.push_back(10);  // 뒤에 삽입(추가)
//	v5.insert(반복자, 10); // 중간 삽입. 반복자 앞에 넣기

	auto p = v5.begin();
	std::advance(p, 2);
	v5.insert(p, 20);

	// 그외에 "삽입반복자"로 넣어도 됩니다.

	// 3. 접근
	int n1 = v5.front(); // 1번째 "요소" 꺼내기. 제거는 안됨. 
						 // 그래서 vector도 가능. 
	int n2 = v5.back();  // 제일 뒤에 요소 꺼내기..

	auto p1 = v5.begin(); // 1번째 요소를 가리키는 반복자 꺼내기

	int n3 = *p1; // 이렇게 하면 1번째 요소

	// 중간 접근
	int n4 = v5[1];    // vector, deque 만 가능, list 안됨
	int n5 = v5.at(1); // vector, deque 만 가능, list 안됨
					   // 위 2줄의 차이점은 나중에 나옵니다.
					   // at() 보다 [] 사용하세요.

	// list라면 중간 접근 어떻게 하나요 ? 
	// => 반복자 밖에 없습니다.
	std::list<int> s = { 1,2,3,4,5 };

	auto p3 = s.begin();
	std::advance(p3, 3);
	int n6 = *p3;

	// 4. 요소 변경
	
	v5.assign( s.begin(), s.end() );

	show(v5);
}