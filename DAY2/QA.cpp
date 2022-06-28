// QA
#include <iostream>
#include <list>

int main()
{
	std::list<int> s = { 1,2,3,4,5 };

	// 아래 코드의 원리를 알아 두세요
	for (auto e : s)	// s 자리에는 컨테이너, 배열이 가능합니다.
	{					// 반복자를 넣을수는 없습니다.
		// e 를 사용하는 코드 
	}


	// 위 "for" 문은 컴파일시에 아래 처럼 변경됩니다.
	auto first = s.begin(); // s가 배열이면 std::begin(s)
	auto last = s.end();

	for (; first != last; ++first)
	{
		auto e = *first;
		//-----------------
		// e를 사용하는 코드
	}
}