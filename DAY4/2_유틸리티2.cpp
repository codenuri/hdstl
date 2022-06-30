#include <tuple>
#include <iostream>

int main()
{
	// pair : C++98. ���� �ٸ� Ÿ���� ��ü 2�� ����
	std::pair<int, double> p1(3, 3.4);

	// pair �� 2�� �̻��� �����Ҽ��� �ֽ��ϴ�.

	std::pair<int, std::pair<char, double>> p2(3, 
								std::pair<char, double>('A', 3.4));

	std::cout << p2.second.second << std::endl; // 3.4 �������� ? ä�� ������.

	// C++98 ������ pair �� ����ؼ� ��ó�� �������� �����ϱ⵵ �߽��ϴ�.
	// �׷���, �ʹ� �����ϰ� �����մϴ�.
	// �׷��� C++11 ���� tuple �� ���Խ��ϴ�.
	std::tuple<int, char, double> t3(3, 'A', 3.4);

	// �� ��� ������ "std::get" �� ����մϴ�
	std::get<0>(t3) = 100;

	std::cout << std::get<0>(t3) << std::endl;

}

