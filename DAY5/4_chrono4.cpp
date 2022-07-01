#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std::chrono;

// system_clock : ���� �ð��� ������ ����ϴ� Ŭ����, non monotonic clock
// time_point   : �ð��� �������� duration<>�� �����ϴ� Ŭ����

//				  ex) 1970�� 1�� 1�� ���� 16880 �ð� ���


int main()
{
	// 1. ���� �ð��� ��� ���
//	system_clock::time_point tp = system_clock::now();

	std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();

	// tp : ���ؽð� ���� ���� ~ ŭ ��� �ߴ�.

	// epoch time : ���� �ð��� 1970�� 1�� 1�Ϸ� �ϴ� �ð�


	// 2. time_point => duration ����... ���е��� �������� ��� ����� ĳ���� �ʿ�..
	nanoseconds nanosec = tp.time_since_epoch();
						// 1970�� 1�� 1���� �������� �󸶳� ����������
						// nano second ������ ������

	seconds     sec     = duration_cast<seconds>(tp.time_since_epoch());
	
	std::cout << nanosec.count() << std::endl;
	std::cout << sec.count() << std::endl;

	using days = duration<int, std::ratio<60 * 60 * 24>>;
	std::cout << (duration_cast<days>(tp.time_since_epoch())).count() << std::endl;


	// 3. time_point => Į���� ������ ��¥�� �����ϱ�
	time_t t = system_clock::to_time_t(tp); // 1. time_point => struct time_t
	std::string s = ctime(&t);					// 2. struct time_t => char*
	std::cout << s << std::endl;
}



