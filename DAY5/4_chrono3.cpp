#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono;
using namespace std::literals; // 1min, 1s, 1ms 등을 위해서

int main()
{
	// 1. predefined typedef
	hours		 h(1);   // using hours = duration<long long, ratio<3600,1>>;
	minutes      m  = h;
	seconds      s  = h; // using seconds = duration<long long, ratio<1,1>>;
	milliseconds ms = h;
	microseconds us = h;
	nanoseconds  ns = h;

	std::cout << h.count() << std::endl; // 1
	std::cout << m.count() << std::endl; // 60
	std::cout << s.count() << std::endl; // 3600
	std::cout << ms.count() << std::endl;
	std::cout << us.count() << std::endl;
	std::cout << ns.count() << std::endl;


	// 2. literals( h, min, s, ms, us, ns )
	// => C++11 부터 지원 되는 문법 - "user define literal 이라는 문법"
	seconds sec = 1min;

	sec = 1min + 3s;
	sec += 40s;
	std::cout << sec.count() << std::endl; // 103

	seconds sec2 = 1min + 3s;
	std::cout << sec2.count() << std::endl; // 63

	std::chrono::seconds sec3 = 30s; // 정확한 표기
}