// 134page ~
#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};

// 아래 Ptr 이 핵심입니다.
// 개념 : 임의 타입의 객체가 "다른 타입의 포인터 역활"을 하는 것
// 원리 : -> 와 * 연산자를 재정의 해서 "포인터 처럼 보이게" 만드는 것
// 장점 : 진짜 포인터가 아니라 객체라는 점 입니다.
//       진짜 포인터는 생성/복사/대입/소멸에 과정에 추가적인 작업을 할수 없습니다
//       객체는 "생성/복사/대입/소멸"의 과정에 약속된 함수가 호출됩니다.
//       그래서 추가의 작업을 할수 있습니다.
//       대표적인 기능이 "소멸자 에서의 자동 삭제 기능" 입니다.

class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }

	~Ptr()
	{
		delete obj;
	}
};
int main()
{
	// "Ptr" 타입의 "객체" p가
	// "Car" 타입의 "포인터" 처럼 사용됩니다.
	Ptr p = new Car; // Ptr p( new Car ) 로 생각하세요. 

	p->Go(); // ( p.operator->())Go() 의 모양인데
			 // ( p.operator->())->Go() 처럼 해석됩니다.

	(*p).Go(); // ( p.operator*() ).Go() 입니다.
}


void foo()
{
	Car* p;
	if (사용자 입력 == 1)
	{
		Car c; // 이렇게 만든 객체는 무조건 수명이 정해져 있습니다.
		p = new Car; // 이렇게 만든 객체는 사용자가 명시적으로 지울때 까지
					// 계속 살아 있습니다. "수명관리를 자유롭게!!!"

	}			// <== c 는 무조건 여기서 파괴!
	else
	{
		// 다른 작업
	}
	//.. 
}


