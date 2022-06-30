#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
	// pair 를 저장하는 hash 입니다.
	std::unordered_map<std::string, std::string> m;

	m["mon"] = "월요일";

	auto p = m.begin();

	std::cout << p->first << std::endl;
	std::cout << p->second << std::endl;
}

// 입력 순서대로 (= 정렬) 저장되지 않았다의 의미가 unordered 인거죠? 
// => 입력순서뿐아니라, 어떤 기준(크기)으로도 정렬되지 않았다입니다.

// std::set 은 입력 순서가 아닌, 크기(std::less) 로 정렬 되었습니다.


