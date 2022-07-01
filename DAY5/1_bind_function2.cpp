#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

class Dialog
{
public:
	void Init(int a, int b)
	{
		printf("Dialog Init : %d, %d\n", a, b);
	}
};

int main()
{
	// C 언어의 함수 포인터는 유연성이 부족합니다.
//  void(*f)(int) = &f1; // ok

//	f = &f2; // error. f는 인자 한개짜리 함수 주소만 가능한데, f2는 인자가2개

	// C++11 에서 도입된 std::function 은 "함수포인터"를 흉내낸
	// 클래스 템플릿 입니다.
	// std::function<함수타입>
	// void(int)    : 함수 타입
	// void(*)(int) : 함수 포인터 타입
	std::function<void(int)> f;
	
	f = &f1;  // & 없어도 됩니다.

	f(10); // f1(10);

	// f 에는 f2, f3, f4등의 함수 주소도 담을수 있습니다.

	f = &f2; // error
	f = std::bind(&f2, _1, 3); // ok

}












