#include <iostream>
#include <tuple>

int main()
{
	// pair :  ���� �ٸ� Ÿ�� 2���� �����Ҽ� �ִ� ����ü �Դϴ�.
	std::pair<int, double> p1(1, 3.4); // ��������� Ÿ���� �����ϴ� ���

	auto p2 = std::make_pair(1, 3.4);	// �Լ� ���ø��� ����ϴ� ���
										// Ÿ���� �������� �ʾƵ� �ȴ�.

	std::tuple<int, double, char, int> t1(1, 3.4, 'A', 10);
							// ���� �ٸ� Ÿ���� N�� ���� ������ ����ü

	auto t2 = std::make_tuple<int, double, char, int>(1, 3.4, 'A', 10);
	auto t3 = std::make_tuple(1, 3.4, 'A', 10); // ok. Ÿ�� ����!

	// �׷���, C++17 ���ʹ� �Ʒ�ó���� �ص� �˴ϴ�.
	std::tuple t4(1, 3.4, 'A', 10); // ok.
}