// C++ Concurrent Programming - 3일과정 ( C++20포함)
#include <iostream>

// C++11 부터 스레드를 STL 에서 지원
#include <thread> 
#include <chrono>
using namespace std::literals;
// 1. this_thread namespace 안에 도움 함수 4개 지원

int main()
{
	std::cout << std::this_thread::get_id() << std::endl; // 스레드ID

//	std::this_thread::sleep_for( 1000 );	// 스레드 재우기
											// error
											// 인자로 chrono 라이브러리전달
	std::chrono::seconds sec(3);
	std::this_thread::sleep_for(sec); //3초 재우기
	std::this_thread::sleep_for(3s); //이 표기도 가능

	std::this_thread::sleep_until(std::chrono::system_clock::now() + 3s);


	std::this_thread::yield(); // 현재 스레드의 남은 실행시간을 포기하고
								// 다른 스레드를 실행해 달라.
}


