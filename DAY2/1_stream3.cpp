#include <iostream>
#include <iterator>
#include <list>
#include <fstream>

int main()
{
	std::ofstream f("a.txt"); // 출력 파일
	std::ostream_iterator<int> p1(f, " ");


	std::ifstream fin("1_stream3.cpp"); // 현재 파일 이름 넣으세요
//	std::istream_iterator<char> p2(fin);
//	std::istream_iterator<char> p3;		// 디폴트 생성자는 "EOF"를 의미

	// 공백도 입력 받으려면 아래처럼 하면 됩니다.
	// istream_iterator     : white space(space, tab, enter 등) 입력안됨
	// istream_iterator_buf : white space(space, tab, enter 등) 입력
	std::istreambuf_iterator<char> p2(fin);
	std::istreambuf_iterator<char> p3;		// 디폴트 생성자는 "EOF"를 의미

//	char c = *p2; 
//	std::cout << c << std::endl; // #

	std::ostream_iterator<char> p4(std::cout, "");

	std::copy(p2, p3, p4); // ??
}