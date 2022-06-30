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
//	sprintf(s, "d = %lf", d); // 문자열이 8자를 넘으면 오버플로우!!
//	snprintf(s, 8, "d = %lf", d); // 문자열이 8자를 넘으면 잘립니다.
		
	// C++ 스타일 
	// => 다양한 형태의 객체(변수)들을 한개의 문자열로 변경하는것
	std::ostringstream oss;
	oss << "d = " << d;    // cout 처럼 사용하세요		
							// 필요한 만큼 메모리가 할당되게 됩니다.
							// oss 의 내부 "string" 에 자동 보관
	oss << "문자열 = , " << 20;

	std::string s1 = oss.str();

	std::cout << s1 << std::endl;

	// string 자체는 "<<" 연산은 안됩니다.
//	std::string ss = 

}
