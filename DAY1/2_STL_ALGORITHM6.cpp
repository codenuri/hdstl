#include <iostream>

// find 정리

// 하는일 : 임의 타입의 배열의 [first, last) 구간에서 선형검색 수행

// 구간의 타입 : 반드시 포인터 일 필요는 없다. 
//				단, !=, ==, *, ++ 연산이 가능해야 한다.
// 
// 구간의 이동 : 전위형 ++ ( ++first)
// 실패의 전달 : last 

// <algorithm> 이라는 표준 헤더에 이미 아래와 같은 find 가 있습니다.

// cppreference.com 에서 "std::find" 찾아 보세요.
template<typename InputIter, typename Val>
InputIter find(InputIter first, InputIter last, const Val& c)
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

// p가 반복자 일때
// 입력 반복자 : =*p,  ++p  가 가능한 반복자

// std::find 같은 알고리즘의 요구 조건을 논리적으로 표현하기 위한 용어

// 그런, 입력 반복자를 가지는 컨테이너는 뭔가요 ?
// list 는 "양방향 반복자"입니다. 그런데. 입력 반복자의 모든 조건을 충족합니다.