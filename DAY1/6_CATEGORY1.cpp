// 53 page ~
#include <forward_list> // �̱۸���Ʈ
#include <list>			// ������Ʈ

int main()
{
	std::forward_list<int> s1 = { 1,2,3 };

	std::list<int> s2 = { 1,2,3 };

	auto p1 = s1.begin();
	auto p2 = s2.begin();
	
	// ������ ������ ã�� ������.
	++p1; // ok
	--p1; // error. �̱۸���Ʈ�� ���� �������θ� �̵� �����ϴ�.
	++p2; // ok
	--p2; // ok

}