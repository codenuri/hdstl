#include <iostream>
#include <thread> 

void foo(int n, double d)
{
	std::cout << "foo" << std::endl;
}

class Test
{
public:
	void goo(int n, double d)
	{
		std::cout << "goo" << std::endl;
	}
};

int main()
{
	// 핵심 1. 스레드를 생성해서 원하는 함수를 실행하는 방법
	// C언어의 스레드    : 반드시 스레드 함수는 void* 를 인자로 받아야 한다.
	// STL std::thread : 어떤 모양의 함수도 스레드로 수행가능

	std::thread t1(&foo, 1, 3.4); // 스레드 생성됨. 

	// 핵심 2. 스레드를 생성한 경우, 반드시 아래 2개중한개를 해야 합니다.
	t1.join();   // 스레드 종료시 까지 대기
//	t1.detach(); // 스레드 핸들 떼어 내기(자식 스레드와 분리하겠다.)

	// 핵심 3. 어떠한 함수도 스레드로 수행가능합니다.
	Test test;

	std::thread t2(&Test::goo, &test, 1, 3.4); // 멤버 함수 수행
						// => 새로운 스레드가 test.goo(1,3.4) 수행
	t2.join();
}


