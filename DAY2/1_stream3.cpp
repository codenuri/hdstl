#include <iostream>
#include <iterator>
#include <list>
#include <fstream>

int main()
{
	std::ofstream f("a.txt"); // ��� ����
	std::ostream_iterator<int> p1(f, " ");


	std::ifstream fin("1_stream3.cpp"); // ���� ���� �̸� ��������
	std::istream_iterator<char> p2(fin);
	std::istream_iterator<char> p3;		// ����Ʈ �����ڴ� "EOF"�� �ǹ�

//	char c = *p2; 
//	std::cout << c << std::endl; // #

	std::ostream_iterator<char> p4(std::cout, "");

	std::copy(p2, p3, p4); // ??
}