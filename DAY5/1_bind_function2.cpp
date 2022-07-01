#include <iostream>
#include <functional> // std::function, std::bind 를 위한 헤더.
using namespace std::placeholders; // _1, _2, 

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
	// => std::bind()로 인자를 고정한 결과로 나오는 함수를 담을수 있다는것

//	f = &f2; // error
	f = std::bind(&f2, _1, 3); // ok

	f(10); // f2(10,3) 의 의미

	//=====================
	f = std::bind(&f3, 2, _1, 1 );

	f(10); // f3(2, 10, 1) 의 의미가 되도록 만들어 보세요

	// f 에는 멤버 함수의 주소도 담을수 있습니다.
	// => 멤버 함수를 호출하려면 객체가 필요 합니다
	Dialog dlg;
	f = std::bind(&Dialog::Init, &dlg, _1, 3);

	f(10); // dlg.Init(10, 3) 의 의미

	// 결론. "std::function<void(int)>" 인 f 에는
	// => 인자가 int 한개 이상 있는 모든 종류의 함수(함수객체)를
	// => 다 보관할수 있습니다.(std::bind 사용해서)
}












