#include <iostream>
#include <unordered_set>
#include "show.h"

// tree : ������ ����, �˻��� ������.
// hash : ���� ���� �ȵ�. �˻��� ������.
// 
// �Ϲ����� ��Ȳ������ hash �� tree ���� ���� ������.

// std::set           : tree �� ����ϴ� set - C++98
// std::unordered_set : hash �� ����ϴ� set - C++11
//		(������ �ȵ� set �̶�� �ǹ�)

// unordered_set 

int main()
{
	// �ٽ� 1. �ؽ� �Լ�
	// => hash ���̺� ����Ÿ�� �����ϱ� ����, ����� index�� ��� �Լ�
	// => C++ǥ���� �Լ� ��ü�� ����

	std::hash<int> hi;
	std::hash<double> hd;
	std::hash<std::string> hs;

	std::cout << hi(33) << std::endl;
	std::cout << hd(3.3) << std::endl;
	std::cout << hs("hello") << std::endl;

	std::cout << hi(33) << std::endl;

}

