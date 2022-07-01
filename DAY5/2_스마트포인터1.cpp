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
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }
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


