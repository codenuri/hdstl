#include <iostream>
#include "show.h"

#include <set> // Red Black Tree�� ����

int main()
{
	std::set<int> s;

	s.insert(20); 
	s.insert(30); 
	s.insert(15);
	s.insert(5);
	s.insert(40);

	// �ٽ� 1. set �� ����� �ߺ��� ������� �ʽ��ϴ�.
	// insert �� ��ȯ Ÿ���� pair �Դϴ�
	std::pair<std::set<int>::iterator, bool> ret = s.insert(15);

	if (ret.second == false)
	{
		std::cout << "����" << std::endl;
		std::cout << *(ret.first) << std::endl; // 15
	}



	auto p = s.begin();.

	while (p != s.end())
	{
		std::cout << *p << std::endl;
		++p; 
	}
}








