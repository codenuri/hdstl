#include <stack>
#include <queue> // queue, priority_queue
#include <iostream>
#include "show.h"
// priority queue 는 vector 를 컨테이너로 써도 되는건가요?
// => 양쪽이 열려 있을필요 없습니다.

// priority queue이면 sequence container 말고, 
// set 같은 tree를 이용해서 구현하지 않은 이유가 있을까요 ??
// => set, hash 다 따로 있으므로
// => sequence container 로만 사용해서 구현한 것을 제공하려고 한것 입니다.

int main()
{
	// queue : FIFO, 먼저 넣은 요소가 먼저 나옵니다.
	// 우선순위큐 : 요소를 꺼낼때 우선순위가 가장 높은
	//			요소가 나오게 된다.
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



