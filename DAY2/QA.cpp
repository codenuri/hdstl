// QA
#include <iostream>
#include <list>

int main()
{
	std::list<int> s = { 1,2,3,4,5 };

	// �Ʒ� �ڵ��� ������ �˾� �μ���
	for (auto e : s)	// s �ڸ����� �����̳�, �迭�� �����մϴ�.
	{					// �ݺ��ڸ� �������� �����ϴ�.
		// e �� ����ϴ� �ڵ� 
	}


	// �� "for" ���� �����Ͻÿ� �Ʒ� ó�� ����˴ϴ�.
	auto first = s.begin(); // s�� �迭�̸� std::begin(s)
	auto last = s.end();

	for (; first != last; ++first)
	{
		auto e = *first;
		//-----------------
		// e�� ����ϴ� �ڵ�
	}
}