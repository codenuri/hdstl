#include <iostream> // 표준 입출력 스트림
#include <fstream>  // 화일 스트림
#include <sstream>  // 메모리(스트링)스트림
#include <string>

int main()
{
	std::ostringstream oss; // 메모리 출력 스트림 
	oss << "hello";

	std::istringstream iss("to be or not to be"); 

	std::string s;

//	std::cin >> s;	// 표준 입력에서 한 단어 입력
	iss >> s;		// iss 의 내부 문자열에서 한단어 입니다.

}
