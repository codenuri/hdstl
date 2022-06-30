#include <iostream>
#include <set>				// tree 기반
#include <unordered_set>	// hash 기반
#include "show.h"

int main()
{
	// 핵심 : set, unordered_set 은 사용법이 거의 동일합니다.

	// set<데이타타입, 비교객체, 메모리 할당기>
	// unordered_set<데이타타입, 해쉬함수, 동질성조사객체, 메모리 할당기>
	std::set<int> s;
//	std::unordered_set<int> s;

	s.insert(10);
	s.insert(35);
	s.insert(20);
	s.insert(25);	// 1. set 이라면 root 와 비교해서 데이타 저장
					// 2. unordered 라면 25를 해쉬 함수에 보내서
					//    index 를 얻은후 저장

	auto p = s.find(20);  // 1. set 이면 root 부터 이진 검색
						  // 2. unordered 라면 
							// 해쉬 함수를 사용해서 index를 얻은후 검색

	std::cout << *p << std::endl;

	show(s); // 1. set 이면 정렬 유지 됩니다.
			 // 2. unordered 라면 정렬되어 있지 않습니다.
}

