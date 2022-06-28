#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10 };

	// 컨테이너에서는 4가지 종류의 반복자를 꺼낼수 있습니다.

	std::list<int>::iterator p1         = s.begin();	// std::begin(s);
	std::list<int>::reverse_iterator p2 = s.rbegin();	// std::rbegin(s);
	std::list<int>::const_iterator p3	= s.cbegin();	// std::cbegin(s);

	*p3 = 0; // error. const_iterator 는 읽기만 가능합니다.

	std::list<int>::const_reverse_iterator p4 = s.crbegin();// std::crbegin(s);

}
