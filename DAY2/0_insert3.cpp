#include <iostream>
#include <list>
#include <iterator>

// 삽입반복자종류

int main()
{
	std::list<int> s1 = { 10,20,30,40,50 };
	std::list<int> s2 = { 1, 2, 3, 4, 5 };
	/*
	// 1. 후방 삽입 반복자 - 컨테이너의 push_back 을 역활을 수행
	std::back_insert_iterator<std::list<int>> p1(s2);
	*p1 = 10; // s2.push_back(10)


	// 2. 전방 삽입 반복자 - 컨테이너의 push_front 을 역활을 수행
	std::front_insert_iterator<std::list<int>> p2(s2);
	*p2 = 10; // s2.push_front(10);

	
	// 3. 임의 삽입 반복자 - 컨테이너의 insert 을 역활을 수행
	auto pos = s2.begin();
	++pos;

//	std::insert_iterator<std::list<int>> p3(s2, 위치를 나타내는 반복자);
	std::insert_iterator<std::list<int>> p3(s2, pos);
	*p3 = 10; // s2.insert(pos, 10)
	*/

	// 삽입 반복자는 함수 버전을 사용하는것이 편리합니다.
	std::copy(s1.begin(), s1.end(), std::back_inserter(s2));
			// 1, 2, 3, 4, 5, 10, 20, 30, 40, 50


	for (auto& n : s2)
		std::cout << n << ", ";
}
