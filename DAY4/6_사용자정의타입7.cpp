#include <iostream>
#include <unordered_set>
#include "show.h"

struct People
{
	std::string name;
	int  age;

	People(std::string n, int a) : name(n), age(a) {}
};
// People ��ü �Ѱ��� �޾Ƽ� hash ���� ��ȯ�ϴ� �Լ� ��ü
struct PeopleHash
{
	inline bool operator()(const People& p) const
	{
		std::hash<int> hi;
		std::hash<std::string> hs;

		return hi(p.age) + hs(p.name);
	}
};
// 2���� People�� ���ϴ� �Լ� ��ü
struct PeopleEqual
{
	inline bool operator()(const People& p1, const People& p2) const
	{
		return p1.name == p2.name && p1.age == p2.age;
	}
};
int main()
{
	// ����� ���� Ÿ���� 
	// set �� �������� : ũ�� �񱳰� �Ǿ�� �մϴ�.
	// unordered     : "hash �Լ���ü + ��ü���Լ���ü" �� �־�� �մϴ�.

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


// java������  if/else if/else ����� �ƴϰ� 
// if�� 1���� �Ǵ��Ͽ� �ᱹ insert �Ǿ��� �ɷ� ���Ǵµ� �򰥷��� ���ǵ�Ƚ��ϴ�.
// => C++�� if ���Լ�(root, ���) 
//          else ���Լ�(���, root)
//		    else �̹� ��Ұ� �ִ�.(ã�Ҵ�)

// set���� ���� ���� ������ �� ���� ���� ã���� 
// ������ ������ ��尡 ���� ������ ��尡 ������ �ʴ°ǰ���?
// => ���� ���� ���� ���� ����� "���� �ڽ� �����ʹ� 0" �ϰ̴ϴ�. 
// => �׷��� ���� ������ �����ϴ�.


// C++98 STL
// => container, algorithm, iterator �� ��������� 
//    �ڷᱸ���� �˰��� ������ ���̺귯��...

// C++11 ~ C++17 STL
// => hash ��� �����̳� �߰�, std::array
// => ����Ʈ ������, function, thread, chrono ����  ��ƿ��Ƽ�� ���̺귯�� �߰�

// C++20 STL
// => ranges ��� ���ο� ������ ���̺귯�� �߰�.

