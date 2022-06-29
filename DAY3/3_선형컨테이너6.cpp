#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>
#include "show.h"

// 활용 예제 입니다.
int main()
{
	std::vector<std::string> v;
	std::ifstream f("3_선형컨테이너6.cpp"); // 현재 파일이름

	std::string s;

//	f >> s;				// 파일에서 한 단어 읽기
//	std::getline(f, s); // 파일에서 한 줄(문장) 읽기

	// 파일에서 한줄씩 읽어서 vector에 보관
	while (std::getline(f, s))
		v.push_back(s);
	//----------------------------
//	std::reverse(v.begin(), v.end());

	// v[0] 은 1번째 요소인데, 1번째 요소의 타입이 std::string 이므로
	// string도 begin, end 있습니다.
//	std::reverse(v[0].begin(), v[0].end());

	for (auto& e : v)
	{
//		std::reverse(e.begin(), e.end());

		// 'i' 문자를 공백으로 치환해 달라
		std::replace(e.begin(), e.end(), 'i', ' ');

		// 위 한줄을 참고 해서, "모든 모음"을 공백으로 치환해 보세요.
		// => 최선의 코드를 생각해 보세요..
	}



	//-------------------------------------
	for (auto& n : v)
		std::cout << n << std::endl;
}


