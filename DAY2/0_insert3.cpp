#include <iostream>
#include <list>
#include <iterator>

// ���Թݺ�������

int main()
{
	std::list<int> s1 = { 10,20,30,40,50 };
	std::list<int> s2 = { 1, 2, 3, 4, 5 };
	/*
	// 1. �Ĺ� ���� �ݺ��� - �����̳��� push_back �� ��Ȱ�� ����
	std::back_insert_iterator<std::list<int>> p1(s2);
	*p1 = 10; // s2.push_back(10)


	// 2. ���� ���� �ݺ��� - �����̳��� push_front �� ��Ȱ�� ����
	std::front_insert_iterator<std::list<int>> p2(s2);
	*p2 = 10; // s2.push_front(10);

	
	// 3. ���� ���� �ݺ��� - �����̳��� insert �� ��Ȱ�� ����
	auto pos = s2.begin();
	++pos;

//	std::insert_iterator<std::list<int>> p3(s2, ��ġ�� ��Ÿ���� �ݺ���);
	std::insert_iterator<std::list<int>> p3(s2, pos);
	*p3 = 10; // s2.insert(pos, 10)
	*/

	// ���� �ݺ��ڴ� �Լ� ������ ����ϴ°��� ���մϴ�.
//	std::copy(s1.begin(), s1.end(), std::back_inserter(s2));
// 				// 1, 2, 3, 4, 5, 10, 20, 30, 40, 50

//	std::copy(s1.begin(), s1.end(), std::front_inserter(s2));
				// 50, 40, 30, 20, 10, 1, 2, 3, 4, 5

	// ���� ���� �ݺ��ڸ� ����� �Լ��� ���ڰ� 2�� �Դϴ�.
	// (��������̳�, ��� ��ġ)
	// �Ʒ� �ڵ�� ���ǻ����� ����ؼ� "���ʿ� �ִ� �ڵ�" �Դϴ�.
	std::copy(s1.begin(), s1.end(), std::inserter(s2, s2.begin()));
				// 10, 20, 30, 40, 50, 1, 2, 3, 4, 5

	for (auto& n : s2)
		std::cout << n << ", ";
}
