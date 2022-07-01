#include <iostream>
#include <thread>
#include <atomic>
// atomic

//int x = 0; // �Ϲ� ���� ����.. 
			// ������ �����忡�� ���ÿ� ���� �ϸ� �������� �ʽ��ϴ�.

std::atomic<int> x = 0; // ������ �����忡�� �����ص� �����մϴ�.

void foo()
{
	x.fetch_add(1);

//	++x; // �̷��� �ص� �˴ϴ�.

//	x = x + 1;

}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}