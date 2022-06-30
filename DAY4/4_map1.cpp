// 6_map1
#include "show.h"

#include <map>  

// map : pair 를 저장하는 set,   key 값으로 value 를 저장
int main()
{
	// 핵심 1. map 객체 생성하는 법
	// => set<키값타입,           비교객체, 메모리 할당기>
	// => map<키값타입, value타입, 비교객체, 메모리 할당기>

	std::map<std::string, std::string> m;
		// std::pair<std::string, std::string> 보관

	// 요소 넣기
	// 1. pair 만들어서 넣기
	std::pair<std::string, std::string> p1("mon", "월요일");
	m.insert(p1);

	// 2. make_pair
	m.insert( std::make_pair("tue", "화요일") );


	// 3. C++11 부터는 {}로도 삽입가능
	// => C++11 의 "brace-init" 문법 때문에 가능
	m.insert( { "wed", "수요일" } );
	
	
	// 4. [] 연산자 사용 - m[키값] = value
	m["fri"] = "금요일";


	//------------------------
	
	// 반복자에 대해서
	auto p = m.find("wed"); // find(키값)

	// p를 사용해서 "wed : 수요일" 이라고 출력해보세요

	// [] 연산자
	std::cout << m["sun"] << std::endl; 
}




