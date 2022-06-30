#include <iostream>
#include <unordered_set>
#include "show.h"

// tree : 정렬을 유지, 검색이 빠르다.
// hash : 정렬 유지 안됨. 검색이 빠르다.
// 
// 일반적인 상황에서는 hash 가 tree 보다 좀더 빠르다.

// std::set           : tree 를 사용하는 set - C++98
// std::unordered_set : hash 를 사용하는 set - C++11
//		(정렬이 안된 set 이라는 의미)

// unordered_set 

int main()
{
	// 핵심 1. 해쉬 함수
	// => hash 테이블에 데이타를 보관하기 위해, 저장될 index를 얻는 함수
	// => C++표준은 함수 객체로 제공

	std::hash<int> hi;
	std::hash<double> hd;
	std::hash<std::string> hs;

	std::cout << hi(33) << std::endl;
	std::cout << hd(3.3) << std::endl;
	std::cout << hs("hello") << std::endl;

	std::cout << hi(33) << std::endl;

}

