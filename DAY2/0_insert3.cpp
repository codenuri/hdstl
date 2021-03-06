#include <iostream>
#include <list>
#include <iterator>//  // std::advance


// 위치가 아닌 값을 기준으로 삽입할 수도 있나요?
// => 값을 기준으로 반복자를 찾으세요. std::find()
// => 그리고 반복자를 보내세요.

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
//	std::copy(s1.begin(), s1.end(), std::back_inserter(s2));
// 				// 1, 2, 3, 4, 5, 10, 20, 30, 40, 50

//	std::copy(s1.begin(), s1.end(), std::front_inserter(s2));
				// 50, 40, 30, 20, 10, 1, 2, 3, 4, 5

	// 임의 삽입 반복자를 만드는 함수는 인자가 2개 입니다.
	// (어느컨테이너, 어느 위치)
	// 아래 코드는 임의삽입을 사용해서 "앞쪽에 넣는 코드" 입니다.
//	std::copy(s1.begin(), s1.end(), std::inserter(s2, s2.begin()));
				// 10, 20, 30, 40, 50, 1, 2, 3, 4, 5

	// 임의삽입을 통한 2번째 요소 앞에 삽입
	auto pos = s2.begin();
	++pos;
//	std::advance(pos, 2);
//	std::copy(s1.begin(), s1.end(), std::inserter(s2, pos));
	std::copy(s1.begin(), s1.end(), 
		std::inserter(s2, std::find(s2.begin(), s2.end(), 4)));


	for (auto& n : s2)
		std::cout << n << ", ";
}
// insert 로 여러개 넣으면 : 루프를 만들어야 합니다.
//s2.insert(10);
//s2.insert(20);
//s2.insert(30);
// 삽입반복자를 사용하면    : 한줄로 표현 됩니다.