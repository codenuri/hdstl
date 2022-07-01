#include <thread>
#include <future>
#include <chrono>
#include <iostream>
using namespace std::literals;

int foo()
{
	std::this_thread::sleep_for(5s);

	return 100;
}

int main()
{
	// async로 수행한 함수(스레드)의 결과는 지금이 아닌
	// 미래에 받을수 있게 됩니다.
	std::future<int> ft = std::async(std::launch::async, &foo); // foo를 비동기(스레드)로 실행해 달라
				
	std::cout << "main 스레드 계속 실행" << std::endl;

	// 이제 foo의 결과가 필요하면 아래 처럼 꺼냅니다.
	int n = ft.get();  // 이 순간 스레드가 반환할때 까지 대기 합니다.

	std::cout << n << std::endl;
}




/*
int main()
{
	// 아래 처럼 직접 스레드를 생성하면 스레드 함수의 반환값을
	// 얻는 것이 복잡해 집니다.(스레드간 통신을 직접 구현)
	std::thread t1(&foo);
	t1.join();
}
*/