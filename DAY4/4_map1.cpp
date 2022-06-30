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
	//=======================================
	
	// 반복자에 대해서
	// => 반복자란 "요소를 가리키는 포인터" 라고 생각하세요
	// => map 의 요소를 pair 이므로
	// => map 의 반복자는 "pair를 가리키는 포인터"라고 생각하세요

	auto p = m.find("wed"); // find(키값)

	// p를 사용해서 "wed : 수요일" 이라고 출력해보세요
	std::cout << p->first << " : " << p->second << std::endl;
	std::cout << (*p).first << " : " << (*p).second << std::endl;

	//================================
	// [] 연산자
	// 현재 키값 "sun" 은 없습니다. 아래 코드의 결과 예측해 보세요
	// 1. 키값이 없으므로 예외 발생
	// 2. {"sun", "" } 의 항목을 새롭게 생성 => 정답
	std::string s = m["sun"]; 
				// 1. sun 이라는 키값이 있으면 해당 항목의 value 반환
				// 2. 없으면 {"sun", ""} 의 항목을 생성후 value("")반환

	// 그래서, 특정 키값이 있는지 확인하려면 아래 처럼하지 마세요
	if (m["thu"] == "") // 단순한 확인이 아니라, 없다면 생성됩니다.
	{
	}
	
	// 아래 처럼 하세요
	auto ret = m.find("thu");
	if (ret == m.end())
	{
		// 키값 "thu" 가 없는 경우
	}

	// C++20 부터는 새로운 멤버 함수가 추가된다.
	if ( m.contains("thu") ) // 결국 내부적으로는 위코드 수행
	{
	}
}
// 위 코드는 보면 결국 "영한 사전" 처럼 보입니다.
// 그래서 다른 언어는 "map" 을 "dictionary" 라고도 부릅니다.






