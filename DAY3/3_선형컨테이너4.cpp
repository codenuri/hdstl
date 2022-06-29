#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

// 예전에 만들어 놓은 함수
void foo(int* arr, int sz) {}

int main()
{
	// C언어 : 배열 사용. 
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	foo(x, 10);

	// 배열    : 크기 변경을 할수 없다.
	// vector : 크기 변경 가능

	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// vector 을 사용하는데, 예전에 만들어 놓은 foo에 vector를 보내고 싶다.
	// foo 에 v를 보내 보세요.
//	foo( v, v.size() ); // error
//	foo(&v, v.size()); // error

	foo(&v[0],    v.size()); // ok.. 예전에 사용하던 코드 ( C++11 이전)
	foo(v.data(), v.size()); // ok.. 요즘 스타일( C++11 이후)

	// 참고
	// 반복자가 가리키는 객체의 주소를 알고 싶을 때, 반복자 멤버 변수가 있을까요?
	// v.begin() 을 사용할 수도 있나요?

	auto p = v.begin();
	++p;

	foo(&(*p), v.size() - 1);  // ok..반복자가 가리키는 요소의 주소 꺼내기

	foo(&(*v.begin()), v.size()); // ok

	// &p : 반복자 객체의 주소
	// *p : 반복자가 가리키는 곳의 객체 접근
	// &(*p) : 반복자가 가리키는 곳의 객체의 주소
}


