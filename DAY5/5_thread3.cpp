#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int shared_data = 10;




// lock/unlock �� ���� ����ϸ� �׻� "dead lock" �� ������ �ֽ��ϴ�.
// ��� �ڿ��� "�ڿ� ���� ��ü" �� ����ϴ� ���� �����մϴ�.
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()			  { mtx.unlock(); }
};

// 1. �� lock_guard �� ���ø� �Դϱ� ??
//  => C++ ǥ�ؿ� mutex�� 6�� ���� �Դϴ�.
//  => std::mutex, std::recursive_mutex, std::shared_mutex;
//  => std::timed_mutex, std::timed_recursive_mutex, std::timed_shared_mutex;

// 2. lock �� �ڵ����� �����ϴ� ������ 4�� �Դϴ�.
// lock_guard : �����ڿ��� lock ���θ� mutex ȹ��, ���� �ܼ�
// unique_lock : �����ڿ��� lock, try_lock �� �ٸ� ����� ����
//				 condition_variable �� ������ ����
// shared_lock : shared_mutex �� ����
// scoped_lock : ������ mutex �� ���ÿ� lock

// 3. mutex �ܿ�
// => semaphre, latch, barrier, condition_variable �� ���� ������ �ֽ��ϴ�.


void foo()
{
	{
		std::lock_guard<std::mutex> g(m); // �����ڸ� ������ ������

		//	m.lock();
		// ���� �ڿ� ���	
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

