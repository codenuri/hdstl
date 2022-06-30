#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <queue> // queue, priority_queue
#include "show.h"

int main()
{
	// 다음중 에러를 모두 골라 보세요
	// stack : 한쪽만 열려 있으면 됩니다. list, vector, deque 모두 가능
	std::stack<int, std::list<int>>   s1;
	std::stack<int, std::vector<int>> s2;
	std::stack<int, std::deque<int>>  s3;

	// queue : 양쪽이 열려 있어야 합니다. vector 는 안됩니다.
	std::queue<int, std::list<int>>   q1;
	std::queue<int, std::vector<int>> q2; // 이렇게 사용하지 마세요
	std::queue<int, std::deque<int>>  q3;

	q2.push(10); // ok.. 에러가 없습니다.
				 // 에러가 없다는 것은 넣을때는 vector의 push_back 을
				 // 사용했다는것
	q2.pop();	// vector 의 pop_front() 로 꺼내려는데..
				// vector 는 앞쪽이 막혔으므로 에러..
}



