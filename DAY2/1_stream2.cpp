#include <iostream>
#include <iterator>
#include <list>
#include <fstream>

int main()
{
	// C++ 표준 출력(std::cout) 에 출력하는 반복자
	std::ostream_iterator<int> p(std::cout, " ");


	std::ofstream f("a.txt"); // 출력 파일
	std::ostream_iterator<int> p1(f, " ");

	*p1 = 10;
	*p2 = 20; // a.txt 에 "20" 쓰기
}