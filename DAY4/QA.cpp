#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <algorithm>

int x[5] = { 1,2,3,4,5 };
int* fn() { return x; } // 배열의 시작 주소 반환

int main()
{
//	std::vector<int> c = { 1,2,3,4,5,6,7,8,9,10 };
//	std::list<int>  c = { 1,2,3,4,5,6,7,8,9,10 };
	std::set<int>  c = { 1,2,3,4,5,6,7,8,9,10 };

	auto ret = std::find(c.begin(), c.end(), 6);

	// ret 는 6을 가리키는 반복자 입니다.
	// 반복자는 포인터 처럼 생각할수 있습니다. ( - 연산 가능, 단 임의접근만 )
	// 그런데, ret 가 몇번째 요소인지 알수 있을까요 ?

//	std::cout << ret - c.begin() << std::endl; // 임의접근 반복자만가능
									// vector와 deque

	// 두 반복자의 차이름 구하는 함수 - 임의 접근 반복자가 아니라도 가능
	int n = std::distance(c.begin(), ret); 

	std::cout << n << std::endl;

	// 2번째 요소를 가리키는 반복자를 꺼내고 싶다.
	auto p1 = ++(c.begin());		// 1. ok.. 
	auto p2 = std::next(c.begin()); // 2. 이렇게 해도 됩니다.


	// 1이면 충분한거 같은데.. 왜.. 2를 하나요..??
	// => 아주 드물게, 1이 안될때가 있습니다.
	auto p3 = ++(fn()); // error. 반환된 주소값은 rvalue 입니다.
						// rvalue 는 ++ 안됩니다.
	auto p4 = std::next(fn()); // ok.. 
}

