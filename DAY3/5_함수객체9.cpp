// 3_함수객체7 - 136 page소스
#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less   { inline bool operator()(int a, int b) { return a < b; }};
struct Greater{	inline bool operator()(int a, int b) { return a > b; }};

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ 표준 sort()는 모든 인자가 템플릿 입니다.
	// => 사용자가 사용하는 코드를 보고 실제 sort 함수가 생성된다는 의미
	// 
	// 1. 비교 정책으로 일반함수 사용시
	
	// 장점 : 비교정책을 여러번 교체해도, 생성되는 sort() 함수는 한개 이다.
	//       코드 메모리 증가 안함.

	// 단점 : 비교 정책 함수(cmp1, cmp2)의 구현이 치환 될수는 없다.
	//       느리다.
	//       특히, sort 하려면 요소의 갯수가 많다면 성능저하가 크다.

	std::sort(x, x+10, cmp1); // sort(int*, int*, bool(*)(int, int)) 모양의함수생성
	std::sort(x, x+10, cmp2); // sort(int*, int*, bool(*)(int, int)) 모양의함수생성


	// 2. 비교정책으로 함수객체 사용시

	// 장점 : 비교 정책이 인라인 치환 될수 있다. 빠르다...
	// 단점 : 비교 정책을 교체한 횟수 만큼의 sort 기계어 코드가 생성된다.
	//       코드 메모리가 증가할수 있다.

	Less    f1;
	Greater f2;
	std::sort(x, x+10, f1); // sort( int*, int*,  Less  ) 모양의 함수를 생성
	std::sort(x, x+10, f2); // sort( int*, int*,  Greater  ) 모양의 함수를 생성
}









