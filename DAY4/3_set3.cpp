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

	// �ٽ�. STL ���� �����̳��� Ư¡�� �� �����ϰ� ����ϼ���

	// �Ʒ� �ڵ带 ���� ������
	// "std::find" : ���� �˻��� �����ϴ� �˰���, 
	//				first �� ++ �ϸ鼭 ��� �˻�
	auto ret = std::find(s.begin(), s.end(), 30);
			// => ������ ������, set �� ����ϴ� ������
			// => ���� �˻��� �ƴ�
			// => ���� �˻��� ���ؼ� �Դϴ�.
		
	auto ret2 = s.find(30); // ���� �˻�

	std::cout << *ret2 << std::endl;

	// "�˰���� ������ �̸��� ��� �Լ��� �ִٸ�
	//  ��� �Լ��� ����ض�"


}








