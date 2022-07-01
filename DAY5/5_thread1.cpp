// C++ Concurrent Programming - 3�ϰ��� ( C++20����)
#include <iostream>

// C++11 ���� �����带 STL ���� ����
#include <thread> 
#include <chrono>
using namespace std::literals;
// 1. this_thread namespace �ȿ� ���� �Լ� 4�� ����

int main()
{
	std::cout << std::this_thread::get_id() << std::endl; // ������ID

//	std::this_thread::sleep_for( 1000 );	// ������ ����
											// error
											// ���ڷ� chrono ���̺귯������
	std::chrono::seconds sec(3);
	std::this_thread::sleep_for(sec); //3�� ����
	std::this_thread::sleep_for(3s); //�� ǥ�⵵ ����

	std::this_thread::sleep_until(std::chrono::system_clock::now() + 3s);


	std::this_thread::yield(); // ���� �������� ���� ����ð��� �����ϰ�
								// �ٸ� �����带 ������ �޶�.
}


