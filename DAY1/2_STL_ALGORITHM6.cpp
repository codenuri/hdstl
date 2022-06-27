#include <iostream>

// find 정리

// 하는일 : 임의 타입의 배열의 [first, last) 구간에서 선형검색 수행

// 구간의 타입 : 반드시 포인터 일 필요는 없다. 
//				단, !=, ==, *, ++ 연산이 가능해야 한다.
// 
// 구간의 이동 : 전위형 ++ ( ++first)
// 실패의 전달 : last 

// <algorithm> 이라는 표준 헤더에 이미 아래와 같은 find 가 있습니다.

template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first;
}



int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

//	double* p = find(x, x + 3, 5);
//	double* p = find(x, x + 배열의크기, 5);
//	double* p = find(x, x + sizeof(x) / sizeof(x[0]), 5);
	double* p = find(x, x + std::size(x), 5); // 이렇게 해도 됩니다.
											// 더 좋은 방법도 있는데..
											// 오후에 설명하겠습니다

	if (p == x + 3)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}