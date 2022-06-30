#include <stack>
#include <queue> // queue, priority_queue
#include <iostream>
#include "show.h"
// priority queue �� vector �� �����̳ʷ� �ᵵ �Ǵ°ǰ���?
// => ������ ���� �����ʿ� �����ϴ�.

// priority queue�̸� sequence container ����, 
// set ���� tree�� �̿��ؼ� �������� ���� ������ ������� ??
// => set, hash �� ���� �����Ƿ�
// => sequence container �θ� ����ؼ� ������ ���� �����Ϸ��� �Ѱ� �Դϴ�.

int main()
{
	// queue : FIFO, ���� ���� ��Ұ� ���� ���ɴϴ�.
	// �켱����ť : ��Ҹ� ������ �켱������ ���� ����
	//			��Ұ� ������ �ȴ�.
//	std::priority_queue<int> pq; 
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

	pq.push(10);
	pq.push(-10);
	pq.push(-20);
	pq.push(20);
	pq.push(15);
	std::cout << pq.top() << std::endl; // 20, -20
	pq.pop();
	std::cout << pq.top() << std::endl; // 15

}



