// 3_함수객체1
#include <iostream>

// 함수 객체(function object, functor 라고도 합니다.)
// => ()연산자를 재정의해서 함수 처럼 사용가능한 객체!!

// 왜, 그냥 함수를 만들면 되는데, 함수 객체를 사용하나요 ??!!
// => 아주 많은 장점이 있습니다. C++20 부터는 거의 모든 것이 함수 객체입니다.

// => 1. 상태를 가지는 함수, Closure 만들기
// => 2. 특정 상황에서 일반 함수 보다, 함수 객체가 빠르다.

struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p; // p는 함수가 아닌 "구조체 Plus 타입의 객체" 입니다.

	int n = p(1, 2); // 그런데, p를 마치 함수 인것 처럼 사용합니다.
					 // p.operator()(1,2) 원리 입니다.

	// a + b;	// a, b 가 primitive 타입이면 그냥 덧셈 수행
	//			// a 가 user 타입이면
	//			// a.operator+(b)  처럼 해석 됩니다.
	// a - b;	// a.operator-(b)
	// a();		// a.operator()()
	// a(1,2);	// a.operator()(1,2) 로 해석됩니다.
}
