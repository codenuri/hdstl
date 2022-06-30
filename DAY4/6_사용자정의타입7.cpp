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
	// unordered     : hash 함수 가 있어야 합니다.

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

