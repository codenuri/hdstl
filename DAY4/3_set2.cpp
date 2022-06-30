#include <iostream>
#include "show.h"

#include <set> // Red Black Tree�� ����

int main()
{
	std::set<int> s;
//	std::set<int, std::greater<int> > s; // �̷��� �ϸ�
								// �Ʒ� �ٽ� 1�� ret Ÿ�Ե� �����ؾ� �մϴ�.
	s.insert(20); 
	s.insert(30); 
	s.insert(15);
	s.insert(5);
	s.insert(40);

	// �ٽ� 1. set �� ����� �ߺ��� ������� �ʽ��ϴ�.
	// insert �� ��ȯ Ÿ���� pair �Դϴ�
	// ��ȯ�� pair �� first, second �ǹ̵� �˾� �μ���
	// ret.first : �̹� �����ϴ� ��Ҹ� ����Ű�� �ݺ���
	// ret.second : ����/���� ���θ� ���� bool ��
	std::pair<std::set<int>::iterator, bool> ret = s.insert(15);
	auto ret = s.insert(15);

	if (ret.second == false)
	{
		std::cout << "����" << std::endl;
		std::cout << *(ret.first) << std::endl; // 15
	}

	// �ٽ� 2. set �� ��� ������ insert(emplace) �� ��밡���մϴ�.
	//        push_xxx() �迭 �Լ��� ����Ҽ� �����ϴ�.
//	s.push_back(90); // �ɱ�� ?? error.

	
	// �ٽ� 3. 
	auto p = s.begin(); 
//	*p = 30; // error. �б⸸ �����ϰ�
			 // ����� �ȵ˴ϴ�.


	while (p != s.end())
	{
		std::cout << *p << std::endl;
		++p; 
	}
}








