#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

// 5���� iterator category - 53page ǥ
// �Է¹ݺ��� : =*p, ++
// ��¹ݺ��� : *p=, ++ 
// -- ��2���� ��Ƽ �н� ���� �ȵ˴ϴ�, �Ʒ� 3���� ��Ƽ �н� ���� �˴ϴ�.// 
// �������ݺ��� : =*p, ++			�̱۸���Ʈ
// ������ݺ��� : =*p, ++, --		������Ʈ
// �������ٹݺ��� : =*p, ++, --, +, -, []  ���ӵ� �޸𸮿� ������ ����

// continuous(C++17)

int main()
{
	std::forward_list<int> s1 = { 1,2,3 };
	std::list<int> s2 = { 1,2,3 };
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	// ���� �Ʒ� �ڵ���� ������ ������
	std::reverse(s1.begin(), s1.end());
	std::reverse(s2.begin(), s2.end());

	std::sort(v.begin(),  v.end());
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());

}