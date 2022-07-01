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

	foo( std::shared_ptr<int>(new int), goo() );			
	
}

void foo( std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }

