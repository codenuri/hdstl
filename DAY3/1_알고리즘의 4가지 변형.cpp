#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

// �˰����� 4���� ���� - 94 page

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v2 = { 0,0,0,0,0,0,0,0,0,0 };

	// 1. �⺻��
//	auto p1 = std::remove(v1.begin(), v1.end(), 3);


	// 2. ������(predicator) ����
//	auto p2 = std::remove_if(v1.begin(), v1.end(),
//								[](int n) { return n % 2 == 0; });

	// 3. ����(copy) ����
	// A. v1=>v2�� copy �� ���� v2�� remove �ϸ� �Ǵµ� 
	//    �� remove_copy ��������� ?
	//    => copy �� remove �ϴ� �� ���� remove_copy �� �����ϴ�.
	// 
	// B. ��ȯ�� p1�� v2�� �ݺ���
	//    => �Ʒ� �ڵ� ������ v1 ��ü�� ��ȭ�� �����ϴ�. 
	//    => v2�� ��� ��ġ ���� ���� �Ǿ����� ������ ��ȯ������ ���ɴϴ�.
//	auto p1 = std::remove_copy(v1.begin(), v1.end(), v2.begin(),  3);

	// 4. ���� ������ ����
	auto p1 = std::remove_copy_if(v1.begin(), v1.end(), v2.begin(), 
						[](int n) { return n % 2 == 0; });
	// p1�� v2�� �ݺ��� �̹Ƿ� �ʿ� ���� ���� ���� �Ϸ���
	v2.erase( p1, v2.end() );

	show(v1); // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	show(v2); // 1, 3, 5, 7, 9
}
