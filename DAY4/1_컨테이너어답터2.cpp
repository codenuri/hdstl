// 3개의 컨테이너 어답터가 있습니다.
#include <stack>
#include <queue> // queue, priority_queue
#include <list>
#include "show.h"

// container adapter 
// => sequence container 의 멤버 함수 이름을 변경해서 다른 것처럼 보이게
// => 만든것
// => stack, queue, priority_queue 가 있습니다. ( 3개 )

int main()
{
	std::stack<int> s1;
//	std::stack<int, std::list<int> > s1; // 내부 컨테이너 변경

	s1.push(10);
	s1.push(20);
	s1.push(30);

	// 주의!. top 은 반환만하고, 제거는 안합니다.
	std::cout << s1.top() << std::endl; // 30
	std::cout << s1.top() << std::endl; // 30

	s1.pop(); // 제거만

	std::cout << s1.top() << std::endl; // 20

	// 그냥 list 를 한쪽 방향으로 사용하면 되는데.. 왜 stack 을 만들었나요 ?
	std::list<int> ss;  // list 를 한쪽으로만 사용해야지!! 
	ss.push_back(10);   // 라고 결심했는데..
	ss.push_back(20);

	ss.push_front(30); // 실수했다!!! => 실수 할수 없게 하는게 최선 아닐까요 ?

	// std::stack<int> s; 로 하면 절대 앞에 넣을수 없습니다
}
