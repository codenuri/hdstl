#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

// 핵심 : 알고리즘과 동일한 이름의 멤버 함수가 있다면
//       => 멤버 함수를 사용해라. (84page. 멤버함수가 좋은 경우가 있다.)


// 왜. 알고리즘(일반함수) 와 동일한 이름의 멤버함수 가 존재 합니까 ?

// 1. 알고리즘에 보낼수 없을때 다른 구현을 제공하기 위해
//    => list 는 std::sort() 에 보낼수 없기 때문에 멤버 함수 sort 제공


// 2. 알고리즘에 보낼수도 있지만, 해당 컨테이너만의 더 좋은 구현이 존재 할때
//    => list 는 std::remove()에 보낼수 있지만, 멤버 함수 remove가 더 좋다.

// 결론, 임의 컨테이너에 어떤 일을 하고 싶다면 !!!
// 1. "멤버함수" 에서 먼저 찾아라.. 
// 
// 2. "멤버함수" 에 없으면 "알고리즘(일반함수)"를 찾아라
// 
// 3. "알고리즘(일반함수)" 에도 보낼수 없다면 해당 컨테이너가 과연 그일을 할수 있는가 다시 생각해보자

//linked list의 장점이 보통 insert / delete인것으로 알고있는데 아까 말씀하신것처럼,
//결국 insert 연산에서 push_back을 사용해서 구현하면, 
// linked list만의 장점이 없는것이 아닌가용 ? ?

// => 삽입반복자는 결국 "링크드리스트의 멤버 함수 push_back/insert" 을 호출하게 됩니다.
// => 결국 "링크드리스트의 멤버 함수"를 사용한다는 의미. 

//삽입반복자<vector> p1(v);
//삽입반복자<list> p2(s);
//*p1 = 10; // v.push_back(10); // vector의 push_back 호출
//*p2 = 10; // s.push_back(10); // list의 push_back 호출




int main()
{
//	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };
	std::list<int>   v = { 1,2,3,1,2,3,1,2,3,1 };

	// 아래 코드는 vector 뿐아니라 list 에 대해서도 잘 동작 합니다.
	// => 그런데, list 의 경우 아래 4줄은 성능이 좋지 않습니다.
	/*
	auto p = std::remove(v.begin(), v.end(), 3);
	show(v);  

	v.erase(p, v.end());
	show(v);
	*/
	// 아래 처럼 멤버 함수 "remove" 를 사용하는 것이 빠릅니다.
	v.remove(3); // 3을 만들때 마다 바로 제거.

	return 0;
}



















//
