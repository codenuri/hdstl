#include <iostream>
#include "show.h"

#include <set> // Red Black Tree로 구현

int main()
{
	// set : tree(RBTree) 로 구현한 컨테이너
	// 그런데, 왜 이름이 set 인가요 ?
	// => 집합 관련 연산을 제공합니다.(교집합, 합집합, 차집합등)
	//
	// C++ 표준은 set 을 만들때 "반드시 tree"로 만들어라 라고
	// 제한 하지는 않습니다. 단지, "이런 기능이 있어야 한다" 라고만 규정합니다.
	// => 그런데, 대부분 기능을 보면 "tree" 로 구현하게 되어 있습니다.
	// 다른 형태로 만들어도 됩니다
//	std::set<int> s;

	std::set<int, std::greater<int> > s;

	s.insert(20); // 이 요소가 root 가 됩니다.(회전되면 변경될수 있습니다.)
	s.insert(30); // 새로운 요소는 root 와 비교해서 삽입됩니다.
	s.insert(15);
	s.insert(5);
	s.insert(40);

	auto p = s.begin();// 제일 왼쪽 자식을 가리킵니다.

	while (p != s.end())
	{
		std::cout << *p << std::endl;
		++p; // 정렬 상태를 볼수 있도록 이동
	}	
}
// std::set이 hash 등으로 구현되지 않은 이유가 무엇인지 궁금합니다. 
// => 있습니다. 다음 시간에 나옵니다







