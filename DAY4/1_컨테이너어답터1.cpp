#include <iostream>

// list �� �̹� �ֽ��ϴ�
#include <list>
#include <vector>
#include <deque>

// �׷���, ������ �ʿ��մϴ�.
// 1. ���� ������.
// 2. list�� ����ó�� ���̰� ����.

// Adapter ���� : ���� Ŭ������ �������̽�(�Լ��̸�)�� �����ؼ�
//			     ���ο� Ŭ������ ����� ������ ����

// list �� ��� �Լ� �̸��� �����ؼ� stack ó�� ���̰� �մϴ�.
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
#include <stack> // �� �ȿ� �ִ� C++ ǥ�� stack �� ��ó�� �����Ǿ����ϴ�.
				 // ����, "stack adapter" ��� �θ��ϴ�.

int main()
{
	std::stack<int> s; // std::deque �� ����� ����
	std::stack<int, std::vector<int> > s1; // std::vector �� ����ó�� ����Ҽ�	
									 // �ְ� �ش޶�� �ǹ�									
	std::stack<int, std::list<int> > s2;

	s.push(10);
	s.push(20);

	std::cout << s.top() << std::endl;

}
