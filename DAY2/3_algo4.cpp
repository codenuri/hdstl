// 3_algo4.cpp
#include <list>
#include <vector>
#include "show.h"

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// v�� ��� ��Ҹ� "������" ������
	// 1. vector�� ��� �Լ��� "��� ������(reverse)"�� ã�ƶ� - ����.
	// 2. �˰��� std::reverse �� ������.
	std::reverse(v.begin(), v.end());

	show(v); // 10,9, 8,7,6,5,4,3,2,1


	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	s.reverse(); // ��� �Լ��� �ִ�.. �˰��� ���� ����Լ��� ����ض�.

	show(s); // 10,9, 8,7,6,5,4,3,2,1

	// std::reverse : ó����Ұ� ������ ����� swap. ��, �� ��Ҹ� swap �ؼ� ����
	//				  ����� ũ�Ⱑ ũ�ٸ� ������尡 ������ �ִ�.
	// 
	// list::reverse ��� �Լ� : Node �� next/prev �����͸� swap �ϴ� ����
	//						sizeof(������) ũ���� swap ���� ����.
}
