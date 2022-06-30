#include "show.h"
#include <set>

struct Compare
{
	bool operator()(int a, int b) const
	{
		return (a / 10) < (b / 10);
	}
};

int main()
{
	std::set<int, Compare> s;

	// 다음중 실패는 ?
	s.insert(15);
	s.insert(25);
	s.insert(45);
	s.insert(35);
	s.insert(22); // 실패, 10의 자릿수로만 비교 하는데. 25 가 이미 있으므로
					// "25", "22" 의 앞자리는 2로 동일(크지도 않고 작지도 않다)
	show(s);

	// 아래 2개의 검색 결과는 어떻게 나올까요 ?
	// 아래 코드가 equality.. == 로 검색
	auto ret1 = std::find(s.begin(), s.end(), 12); // 실패
	
	if (ret1 == s.end())
		std::cout << "실패" << std::endl;

	// 아래는 equivalency 
	auto ret2 = s.find(12);  // <== 15 검색. 
	std::cout << *ret2 << std::endl; // 15

	auto ret3 = s.find(72);  //  앞자리 7 은 set에 없습니다.
							// 실패, ret3에는 s.end()가 있습니다
	if (ret3 == s.end()) {}
}