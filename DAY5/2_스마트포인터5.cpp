#include <iostream>
#include <memory>

void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ? - 2번
	// 1. new Point(1,2);
	// 2. new 관리객체(참조계수 + 몇가지 추가정보) : 20~30바이트정도크기

	// 아래 코드는 "Point 객체 생성" 과 "관리객체생성" 을 각각 따로 하게 됩니다.
//	std::shared_ptr<Point> sp(new Point(1, 2));

	// 아래 코드는 "Point 객체크기 + 관리객체 크기" 의 메모리를 한번에 할당합니다.
	// 1. "Point 객체크기 + 관리객체 크기" 의 메모리 할당후
	// 2. shared_ptr 을 만들어서 반환
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);
							//  std::make_shared<타입>(생성자인자값);

	// std::make_shared 의 장점
	// 1. 객체와 관리객체의 메모리를 한번에 할당해서 효율적 메모리 관리
	// 2. exception safety 보장 ( 자원 누수 현상 없음)

	//             (2)          (1)      (3)
	foo( std::shared_ptr<int>(new int), goo() );			
	
	// 위 코드가 
	// (1), (2), (3) 의 순서로 실행되면 문제 없습니다. 
	// 그런데
	// (1), (3), (2) 의 순서로 실행되었는데, goo() 함수에서 예외가 발생하면
	//									=> 메모리 누수 입니다.

	// "자원을 할당한후 포인터를", "자원관리 객체에 넘기는 것은"
	// 반드시 "한번의 작업으로 이루어 져야 안전합니다.
	// => 중간에 다른 작업이 끼어 들면 안됩니다.
	// std::make_shared<int>(0) : int 한개 할당하고, 0으로 초기화하고
	//							shared_ptr 만들어서 반환해 달라.
	foo( std::make_shared<int>(0), goo());   
}


void foo( std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }

