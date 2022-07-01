#include <iostream>

// C++11의 스마트포인터를 사용하려면 필요한 헤더
#include <memory>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
	// 핵심 1. = 초기화는 할수 없고, () 초기화만 됩니다.
	// => 생성자가 explicit 라는 의미 입니다.
	// => explicit 생성자는 직접 초기화만 가능합니다.
	std::shared_ptr<int> p1(new int);  // ok    직접(direct) 초기화
//	std::shared_ptr<int> p2 = new int; // error 복사(copy) 초기화


	// 핵심 2. 스마트 포인터의 크기
	std::cout << sizeof(p1)   << std::endl; // 대부분 raw pointer의 
											// 2배 크기 ( 구현에 따라 다를수 있음)

	std::cout << sizeof(int*) << std::endl; // 32bit 환경 4바이트
											// 64bit 환경 8바이트


	// 핵심 3. -> 와 . 연산자
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

	// -> 연산자 : 대상체(Car)의 멤버에 접근 하는 것 	
	sp1->Go();

	// . 연산자 : shared_ptr 자체의 멤버에 접근하는 것
	int n = sp1.use_count(); // 참조계수, 몇개의 스마트포인터가 자원을 공유
							// 하는가?... 2
	std::cout << n << std::endl;
}





