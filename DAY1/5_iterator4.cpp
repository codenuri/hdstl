#include <iostream>
#include <list>   
#include <vector>

// �ݺ��� ��ȿȭ
int main()
{
//	std::vector<int> v = { 1,2,3,4,5 };
	std::list<int>   v = { 1,2,3,4,5 };
	
	auto p = std::begin(v); // v.begin()

	std::cout << *p << std::endl; // 1


	v.resize(10); // vector�� ũ�� ����
					// ���� ���� �޸𸮰� ���Ҵ�˴ϴ�.
					// ������ ���� ��� �ݺ��ڴ� 
					// "��ȿȭ(invalidate)" �˴ϴ�. 
					// ��, list ��� �ݺ��ڰ� ��ȿȭ ���� �ʽ��ϴ�.

	std::cout << *p << std::endl; // ????
}
// cppreference.com ���� "std::vector" �˻� �غ�����.


