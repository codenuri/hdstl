#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std::chrono;

// system_clock : 현재 시간을 얻을때 사용하는 클래스, non monotonic clock
// time_point   : 시간의 시작점과 duration<>을 보관하는 클래스

//				  ex) 1970년 1월 1일 기준 16880 시간 경과


int main()
{
	// 1. 현재 시간을 얻는 방법
//	system_clock::time_point tp = system_clock::now();

	std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();

	// tp : 기준시간 으로 부터 ~ 큼 경과 했다.

	// epoch time : 기준 시간을 1970년 1월 1일로 하는 시간


	// 2. time_point => duration 얻어내기... 정밀도가 낮아지는 경우 명시적 캐스팅 필요..
	nanoseconds nanosec = tp.time_since_epoch();
						// 1970년 1월 1일을 기준으로 얼마나 지났는지를
						// nano second 단위로 꺼내기

	seconds     sec     = duration_cast<seconds>(tp.time_since_epoch());
	
	std::cout << nanosec.count() << std::endl;
	std::cout << sec.count() << std::endl;

	using days = duration<int, std::ratio<60 * 60 * 24>>;
	std::cout << (duration_cast<days>(tp.time_since_epoch())).count() << std::endl;


	// 3. time_point => 칼린더 형태의 날짜로 변경하기
	time_t t = system_clock::to_time_t(tp); // 1. time_point => struct time_t
	std::string s = ctime(&t);					// 2. struct time_t => char*
	std::cout << s << std::endl;
}



