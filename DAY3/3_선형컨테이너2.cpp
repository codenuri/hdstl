
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include "show.h"

int main()
{
	// 1. ����
	std::vector<int> v1;		// �ʱ� ũ��� ����.
	std::vector<int> v2(10);	// 10���� 0���� �ʱ�ȭ
	std::vector<int> v3(10, 3);	// 10���� 3���� �ʱ�ȭ
	std::vector<int> v4(v3);	// v3�� �����ϰ�..

	std::vector<int> v5 = { 1,2,3 }; // 3���� 1, 2, 3���� �ʱ�ȭ
//	std::vector<int> v5 { 1,2,3 };	 // �� �ڵ�� �� �ڵ�� �����մϴ�.

	// �Ʒ� 2�� ������ �� ����ϼ���
	std::vector<int> v6( 10, 3 ); // 10���� 3���� �ʱ�ȭ
	std::vector<int> v7{ 10, 3 }; // 2���� "10, 3"���� �ʱ�ȭ

	std::cout << v6.size() << std::endl; // 10
	std::cout << v7.size() << std::endl; // 2

	// ���� ��� �ڵ�� list, deque �� �����մϴ�.

	// 2. ����, 
//	v5.push_front(10); // ���� ����, ��, vector �� �ȵ�
					   // => ���ӵ� �޸��� ���ʿ� �ִ� ���� �ʹ� ������ ������
						//   ������� ����� �ǵ�.
	v5.push_back(10);  // �ڿ� ����(�߰�)
//	v5.insert(�ݺ���, 10); // �߰� ����. �ݺ��� �տ� �ֱ�

	auto p = v5.begin();
	std::advance(p, 2);
	v5.insert(p, 20);

	// �׿ܿ� "���Թݺ���"�� �־ �˴ϴ�.

	// 3. ����
	int n1 = v5.front(); // 1��° "���" ������. ���Ŵ� �ȵ�. 
						 // �׷��� vector�� ����. 
	int n2 = v5.back();  // ���� �ڿ� ��� ������..

	auto p1 = v5.begin(); // 1��° ��Ҹ� ����Ű�� �ݺ��� ������

	int n3 = *p1; // �̷��� �ϸ� 1��° ���

	// �߰� ����
	int n4 = v5[1];    // vector, deque �� ����, list �ȵ�
	int n5 = v5.at(1); // vector, deque �� ����, list �ȵ�
					   // �� 2���� �������� ���߿� ���ɴϴ�.
					   // at() ���� [] ����ϼ���.

	// list��� �߰� ���� ��� �ϳ��� ? 
	// => �ݺ��� �ۿ� �����ϴ�.
	std::list<int> s = { 1,2,3,4,5 };

	auto p3 = s.begin();
	std::advance(p3, 3);
	int n6 = *p3;

	// 4. ��� ����
	
	v5.assign( s.begin(), s.end() );

	show(v5);
}