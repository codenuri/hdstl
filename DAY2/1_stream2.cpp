#include <iostream>
#include <iterator>
#include <list>
#include <fstream>

int main()
{
	// C++ ǥ�� ���(std::cout) �� ����ϴ� �ݺ���
	std::ostream_iterator<int> p(std::cout, " ");


	std::ofstream f("a.txt"); // ��� ����
	std::ostream_iterator<int> p1(f, " ");

	*p1 = 10;
	*p2 = 20; // a.txt �� "20" ����
}