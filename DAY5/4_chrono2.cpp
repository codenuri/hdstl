#include <iostream>
#include <chrono>
using namespace std::chrono;

// duration ���� : Ư�� ������ ����(tick count)�� ǥ���ϴ� �ڷᱸ��
//				  10�� => 1���� 10��
//					   => 1/1000���� 10000��..

int main()
{
	// 1. duration ���
	duration<int, std::ratio<1, 100>>  d1(2); // 1/100 * 2  => 0.02
	duration<int, std::ratio<1, 1000>> d2(d1); // 20

	std::cout << d2.count() << std::endl;

	std::chrono::duration<int, std::ratio<1, 1000000> > d3(d1);

	std::cout << d3.count() << std::endl; // 20000
	
	//==============================
	using Meter      = std::chrono::duration<int, std::ratio<1, 1>>;
	using CentiMeter = std::chrono::duration<int, std::ratio<1, 100> >;
//	using MilliMeter = std::chrono::duration<int, std::ratio<1, 1000>>;
	using MilliMeter = std::chrono::duration<int, std::milli>;

	using KiloMeter  = std::chrono::duration<int, std::ratio<1000,1>>;

	Meter m(3000); // 3000m
	CentiMeter cm(m);

	std::cout << cm.count() << std::endl; // 300000

//	KiloMeter km = m; // error. ����Ÿ �ս��� ���ɼ��� �ֱ⶧����

	KiloMeter km = std::chrono::duration_cast<KiloMeter>(m);

	std::cout << km.count() << std::endl; // 3
}





