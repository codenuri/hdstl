#include <iostream> // 표준 입출력 스트림
#include <fstream>  // 화일 스트림
#include <sstream>  // 메모리(스트링)스트림
#include <string>

int main()
{
	double d = 3.14;

	// d의 값을 문자열로 변경하려고 합니다.
	// C 스타일
	char s[8];
	sprintf(s, "d = %lf", d); // 문자열이 8자를 넘으면 오버플로우!!
	snprintf(s, 8, "d = %lf", d); // 문자열이 8자를 넘으면 잘립니다.
		
	// C++ 스타일 
	std::ostringstream oss;
	oss << "d = " << d;    // cout 처럼 사용하세요

	std::string s1 = oss.str();

	std::cout << s1 << std::endl;

}
