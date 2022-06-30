#include <iostream>
#include <unordered_set>
#include "show.h"

struct People
{
	std::string name;
	int  age;

	People(std::string n, int a) : name(n), age(a) {}
};
// People 객체 한개를 받아서 hash 값을 반환하는 함수 객체
struct PeopleHash
{
	inline bool operator()(const People& p) const
	{
		std::hash<int> hi;
		std::hash<std::string> hs;

		return hi(p.age) + hs(p.name);
	}
};
// 2개의 People을 비교하는 함수 객체
struct PeopleEqual
{
	inline bool operator()(const People& p1, const People& p2) const
	{
		return p1.name == p2.name && p1.age == p2.age;
	}
};
int main()
{
	// 사용자 정의 타입을 
	// set 에 넣으려면 : 크기 비교가 되어야 합니다.
	// unordered     : "hash 함수객체 + 객체비교함수객체" 가 있어야 합니다.

//	std::unordered_set<People> s;
//  std::unordered_set<People, std::hash<People> > s;

	std::unordered_set<People, PeopleHash, PeopleEqual > s;

	s.emplace("kim", 20); // s.insert( People("kim",20))
	s.emplace("lee", 25);
	s.emplace("park", 30);


	People peo("lee", 25);
	auto p = s.find( peo );

	std::cout << (*p).name << std::endl;
}


// java에서는  if/else if/else 방식이 아니고 
// if만 1차적 판단하여 결국 insert 되었던 걸로 기억되는데 헷갈려서 문의드렸습니다.
// => C++은 if 비교함수(root, 요소) 
//          else 비교함수(요소, root)
//		    else 이미 요소가 있다.(찾았다)

// set에서 가장 작은 값보다 더 작은 값을 찾느라 
// 마지막 종착지 노드가 가장 왼쪽의 노드가 되지는 않는건가요?
// => 가장 작은 값을 가진 노드의 "왼쪽 자식 포인터는 0" 일겁니다. 
// => 그래서 내려 갈수는 없습니다.


// C++98 STL
// => container, algorithm, iterator 를 기반으로한 
//    자료구조와 알고리즘 위주의 라이브러리...

// C++11 ~ C++17 STL
// => hash 기반 컨테이너 추가, std::array
// => 스마트 포인터, function, thread, chrono 등의  유틸리티성 라이브러리 추가

// C++20 STL
// => ranges 라는 새로운 개념의 라이브러리 추가.

