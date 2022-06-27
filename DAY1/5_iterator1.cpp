// iterator1.cpp
#include <iostream>
#include <list>

int main()
{
	int x[5] = { 1,2,3,4,5 };

	int* p = x;
	*p; 
	++p;


	std::list<int> s = { 1,2,3,4,5 };
	std::list<int>::iterator p2 = s.begin();
	*p2; 
	++p2;

	// 반복자의 장점
	// 컨테이너의 내부 구조(자료구조, 메모리 모양)에
	// 상관없이 동일한 방법으로 요소에 접근할수 있다.!!

	// 디자인 패턴에서 "iterator" 패턴.!

	// 사용방법은 "raw 포인터와 동일"
}










