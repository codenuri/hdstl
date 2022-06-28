#include <iostream>
#include <iterator>
#include <list>
#include <fstream>

int main()
{
	// 참고 C++ 파일 입출력은 아래 처럼 객체를 생성합니다.
	std::ofstream fout("a.txt"); // 출력 파일
	std::ifstream fin("1_stream3.cpp"); // 입력파일

	// 이제 사용법은 cout, cin 과 동일합니다.
	fout << 10 << ", " << 3.4;  // 파일에 "10, 3.4" 쓰기

	std::string s;
	fin >> s; // 파일에서 한단어 읽기
}