#include <iostream>
#include <thread>
#include <atomic>
// atomic

//int x = 0; // 일반 전역 변수.. 
			// 여러개 스레드에서 동시에 접근 하면 안전하지 않습니다.

std::atomic<int> x = 0; // 여러개 스레드에서 접근해도 안전합니다.

void foo()
{
	x.fetch_add(1);

//	++x; // 이렇게 해도 됩니다.

//	x = x + 1;

}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}