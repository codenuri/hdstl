#include <iostream>
#include <list>
#include <iterator>

int main()
{
	std::list<int> s = { 1, 2, 3, 4, 5};

	// 컨테이너의 끝에 "추가" 하는 방법

	// 방법 1. 멤버 함수 push_back 사용
	s.push_back(10);


	// 방법 2. 삽입 반복자 사용
//	std::back_insert_iterator<std::list<int>> p(s);	// C++14까지는 타입을전달해야
													// 하는데, 복잡해 보입니다.
													// C++17 부터는 타입생략가능
	// 삽입 반복자의 경우, 위처럼 직접 만들면 복잡해 보입니다.
	// 삽입 반복자를 만드는 함수를 사용하면 편리합니다
	auto p = std::back_inserter(s);

	*p = 20;	// s.push_back(20) 과 동일한 의미.
				// 즉, list 끝에 20 추가
	*p = 30; // s.push_back(30);

	for (auto e : s)
		std::cout << e << ", ";
	std::cout << std::endl;
}
// 반복자
// 1. 컨테이너에서 꺼낼수 있다. : s.begin() 등으로
// 2. raw pointer 도 반복자 이다. : ++로 이동가능하고, *도 가능
// 3. 단독으로 만들어서 사용하는 것들도 있다.
//    => 삽입반복자, 스트림 반복자, 파일시스템반복자등.. 


