// 3���� �����̳� ����Ͱ� �ֽ��ϴ�.
#include <stack>
#include <queue> // queue, priority_queue
#include <list>
#include "show.h"

// container adapter 
// => sequence container �� ��� �Լ� �̸��� �����ؼ� �ٸ� ��ó�� ���̰�
// => �����
// => stack, queue, priority_queue �� �ֽ��ϴ�. ( 3�� )

int main()
{
	std::stack<int> s1;
//	std::stack<int, std::list<int> > s1; // ���� �����̳� ����

	s1.push(10);
	s1.push(20);
	s1.push(30);

	// ����!. top �� ��ȯ���ϰ�, ���Ŵ� ���մϴ�.
	std::cout << s1.top() << std::endl; // 30
	std::cout << s1.top() << std::endl; // 30

	s1.pop(); // ���Ÿ�

	std::cout << s1.top() << std::endl; // 20

	// �׳� list �� ���� �������� ����ϸ� �Ǵµ�.. �� stack �� ��������� ?
	std::list<int> ss;  // list �� �������θ� ����ؾ���!! 
	ss.push_back(10);   // ��� ����ߴµ�..
	ss.push_back(20);

	ss.push_front(30); // �Ǽ��ߴ�!!! => �Ǽ� �Ҽ� ���� �ϴ°� �ּ� �ƴұ�� ?

	// std::stack<int> s; �� �ϸ� ���� �տ� ������ �����ϴ�
}
