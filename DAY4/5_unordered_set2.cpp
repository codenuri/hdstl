#include <iostream>
#include <set>				// tree ���
#include <unordered_set>	// hash ���
#include "show.h"

int main()
{
	// �ٽ� : set, unordered_set �� ������ ���� �����մϴ�.

	// set<����ŸŸ��, �񱳰�ü, �޸� �Ҵ��>
	// unordered_set<����ŸŸ��, �ؽ��Լ�, ���������簴ü, �޸� �Ҵ��>
	std::set<int> s;
//	std::unordered_set<int> s;

	s.insert(10);
	s.insert(35);
	s.insert(20);
	s.insert(25);	// 1. set �̶�� root �� ���ؼ� ����Ÿ ����
					// 2. unordered ��� 25�� �ؽ� �Լ��� ������
					//    index �� ������ ����

	auto p = s.find(20);  // 1. set �̸� root ���� ���� �˻�
						  // 2. unordered ��� 
							// �ؽ� �Լ��� ����ؼ� index�� ������ �˻�

	std::cout << *p << std::endl;

	show(s); // 1. set �̸� ���� ���� �˴ϴ�.
			 // 2. unordered ��� ���ĵǾ� ���� �ʽ��ϴ�.
}

