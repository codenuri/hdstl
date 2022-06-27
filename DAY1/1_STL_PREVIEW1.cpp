// 1_STL_PREVIEW1
#include <iostream>
#include <string>

int main()
{
	char s1[] = "Hello";
	char s2[] = "Hello";

	if (s1 == s2) {} // 문자열 비교가 아닌 배열 주소 비교, 항상 false
					 // "strcmp(s1, s2) == 0"
	
	s2 = s1; // error. 
		     // strcpy(s2, s1) 또는 strcpy_s(s2, strlen(s1)+1, s1)

	// C++ 표준에는 "std::string" 타입 제공
	std::string s3 = "hello";
	std::string s4 = s3;

	if (s3 == s4) {} // 비교도 가능

	s4 = s3 + s3; // 덧셈도 가능
//	s4 = s3 * 3;  // 곱셈은 안됨

}








// Visual studio  사용하시는 분들은

// 1. 프로젝트 열기로 열어 주세요

// 2. "프로젝트 메뉴" => "DAY1 속성메뉴"
//    => 플랫폼 도구집합
//    => Windows SDK 버전 설정해 주세요

