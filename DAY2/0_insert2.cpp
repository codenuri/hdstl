// insert2.cpp
#include <iostream>
#include <algorithm>
#include <list>

// �Լ� ����

int main()
{
	std::list<int> s1 = { 10,20,30,40,50 };
	std::list<int> s2 = { 1, 2, 3, 4, 5 };
	

	// �Ʒ� �ڵ�� s1 �� ������ s2 �� ����� �ڵ�
//	std::copy(s1.begin(), s1.end(), s2.begin());


	// s1�� ������ s2�� ����� ����, ���� �߰��� ���ô�.
	// 1. �ڵ�� ���� �ۼ��Ѵٸ�..
//	for (int i = 0; i < s1.size(); i++)
//	{
//		s2.push_back( s1[i] ); // �׷���, �̷��� �ϸ� [] ������ �ʿ��մϴ�
							   // vector �� �����ѵ�, list�� �ȵ˴ϴ�.
//	}

	// 2. C++11 �� range-for ���
//	for (auto e : s1)
//	{
//		s2.push_back(e); // ok.. 
//	}

	// 3. ���� �ݺ��ڿ� std::copy �˰��� ���
//	std::back_insert_iterator< std::list<int> > p(s2);
//	std::copy(s1.begin(), s1.end(), p);

	// 4. ���� �ݺ��ڸ� ����� �ִ� �Լ� ���
	// => �Ʒ� ������ �� 2�ٰ� �����մϴ�
	std::copy(s1.begin(), s1.end(), std::back_inserter(s2));

	for (auto& n : s2)
		std::cout << n << std::endl; 

	// �ٽ�. �Ʒ� 2���� �������� ��Ȯ�� �˾� �μ���
	std::copy(s1.begin(), s1.end(), s2.begin());	// s2�� �����
	std::copy(s1.begin(), s1.end(), std::back_inserter(s2)); // s2�ڿ� �߰�
}
