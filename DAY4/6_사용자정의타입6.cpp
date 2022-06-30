#include "show.h"
#include <set>

struct Compare
{
	bool operator()(int a, int b) const
	{
		return (a / 10) < (b / 10);
	}
};

int main()
{
	std::set<int, Compare> s;

	// ������ ���д� ?
	s.insert(15);
	s.insert(25);
	s.insert(45);
	s.insert(35);
	s.insert(22); // ����, 10�� �ڸ����θ� �� �ϴµ�. 25 �� �̹� �����Ƿ�
					// "25", "22" �� ���ڸ��� 2�� ����(ũ���� �ʰ� ������ �ʴ�)
	show(s);

	// �Ʒ� 2���� �˻� ����� ��� ���ñ�� ?
	// �Ʒ� �ڵ尡 equality.. == �� �˻�
	auto ret1 = std::find(s.begin(), s.end(), 12); // ����
	
	if (ret1 == s.end())
		std::cout << "����" << std::endl;

	// �Ʒ��� equivalency 
	auto ret2 = s.find(12);  // <== 15 �˻�. 
	std::cout << *ret2 << std::endl; // 15

	auto ret3 = s.find(72);  //  ���ڸ� 7 �� set�� �����ϴ�.
							// ����, ret3���� s.end()�� �ֽ��ϴ�
	if (ret3 == s.end()) {}
}