#include <tuple>
#include <iostream>

int main()
{
	// pair : C++98. ���� �ٸ� Ÿ���� ��ü 2�� ����
	std::pair<int, double> p1(3, 3.4);

	// pair �� 2�� �̻��� �����Ҽ��� �ֽ��ϴ�.

	std::pair<int, std::pair<char, double>> p2(3, 
								std::pair<char, double>('A', 3.4));

	std::cout << ? << std::endl; // 3.4 �������� ? ä�� ������.
}