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
	// �ٽ� 1. �� �����̳��� �ݺ��ڰ� ��� ī�װ����� �ݵ�� �˾ƾ� �մϴ�.
	std::forward_list<int> s1 = { 1,2,3 };	// �������ݺ��� : ++
	std::list<int> s2 = { 1,2,3 };			// ������ݺ��� : ++, --
	std::vector<int> v = { 1,2,3,4,5}; // �������ٹݺ��� : ++, --, +,-,[]
	
	// ���� �Ʒ� �ڵ���� ������ ������
	// �ٽ� 2. �� �˰����� ���ڷ� �޴� �ݺ����� ī�װ��� ������ �ֽ��ϴ�.
	std::reverse(s1.begin(), s1.end()); // error. �̱۸���Ʈ �ݺ��ڴ�
										// ������, -- ���� �ȵ�
	std::reverse(s2.begin(), s2.end()); // ok

//	std::sort(v.begin(),  v.end());
//	std::sort(s1.begin(), s1.end());
//	std::sort(s2.begin(), s2.end());

}