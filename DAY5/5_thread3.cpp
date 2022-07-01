#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int shared_data = 10;




// lock/unlock 을 직접 사용하면 항상 "dead lock" 의 위험이 있습니다.
// 모든 자원은 "자원 관리 객체" 를 사용하는 것이 안전합니다.
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()			  { mtx.unlock(); }
};

// 1. 왜 lock_guard 가 템플릿 입니까 ??
//  => C++ 표준에 mutex는 6개 종류 입니다.
//  => std::mutex, std::recursive_mutex, std::shared_mutex;
//  => std::timed_mutex, std::timed_recursive_mutex, std::timed_shared_mutex;

// 2. lock 을 자동으로 관리하는 도구는 4개 입니다.
// lock_guard : 생성자에서 lock 으로만 mutex 획득, 가장 단순
// unique_lock : 생성자에서 lock, try_lock 등 다른 방법도 가능
//				 condition_variable 과 연동도 가능
// shared_lock : shared_mutex 를 위해
// scoped_lock : 여러개 mutex 를 동시에 lock

// 3. mutex 외에
// => semaphre, latch, barrier, condition_variable 등 많이 도구가 있습니다.


void foo()
{
	{
		std::lock_guard<std::mutex> g(m); // 생성자를 생각해 보세요

		//	m.lock();
		// 공유 자원 사용	
		shared_data = 200;
		//	m.unlock();
	}
	//...
}





int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

