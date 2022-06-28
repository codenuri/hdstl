#include <iostream>
#include <list>
#include <algorithm>
#include <iterator> 


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10 };

//	auto p1 = s.begin();
//	auto p2 = s.end();

	// 아래 처럼 하기위해서, 
	// 인자로 전달된 반복자가 가리키는 요소보다 보다 한개 앞을 가리키도록 설계되었습니다.
//	auto p1 = std::make_reverse_iterator(s.end());
//	auto p2 = std::make_reverse_iterator(s.begin());
	
	auto p1 = s.rbegin(); // std::make_reverse_iterator(s.end())와동일
	auto p2 = s.rend();

	// 주어진 구간에서, 처음 나오는 3을 찾고 싶다.
	// 대부분의 STL 알고리즘은 반복자를 ++로 이동합니다.
	// 하지만, 역반복자 덕분에, 대부분의 알고리즘은 역순으로도 동작할수 있습니다.
	auto ret = std::find(p1, p2, 3);
}
