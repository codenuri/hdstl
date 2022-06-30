#include <iostream>

// list 가 이미 있습니다
#include <list>
#include <vector>
#include <deque>

// 그런데, 스택이 필요합니다.
// 1. 새로 만들자.
// 2. list를 스택처럼 보이게 하자.

// Adapter 패턴 : 기존 클래스의 인터페이스(함수이름)을 변경해서
//			     새로운 클래스를 만드는 디자인 패턴

// list 의 멤버 함수 이름을 변경해서 stack 처럼 보이게 합니다.
/*
template<typename T, typename C = std::deque<T> > 
class stack
{
	C c;
public:
	inline void push(const T& a) { c.push_back(a); }
	inline void pop()			  { c.pop_back(); }
	inline T& top()			  { return c.back(); }
};
*/
#include <stack> // 이 안에 있는 C++ 표준 stack 이 위처럼 구현되었습니다.
				 // 흔히, "stack adapter" 라고 부릅니다.

int main()
{
	std::stack<int> s; // std::deque 를 사용한 스택
	std::stack<int, std::vector<int> > s1; // std::vector 를 스택처럼 사용할수	
									 // 있게 해달라는 의미									
	std::stack<int, std::list<int> > s2;

	s.push(10);
	s.push(20);

	std::cout << s.top() << std::endl;

}
