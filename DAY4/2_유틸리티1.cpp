#include <iostream>
#include "show.h"

template<typename T> void foo(T a) {}

int main()
{
	// pair : ���δٸ� Ÿ�� 2���� �����ϴ� ����ü
	std::pair<int, double> p1(3, 3.4);

	std::cout << p1.first  << std::endl; // 3
	std::cout << p1.second << std::endl; // 3.4


	// std::make_pair �� ����ϸ� "Ÿ�� ����" ������ �����Ҽ� �ֽ��ϴ�.
	auto p2 = std::make_pair(3, 4);

	// C++17 ���� ���ʹ� �Ʒ� ó�� ���� std::pair �� ����ص�
	// "Ÿ�� ����" ���� �����մϴ�.
	std::pair p3(1, 3.4);

	std::pair p4; // error. C++17 ���Ķ�. Ÿ���� �߷��Ҽ� �ִ�
					// ������ ������ ���� �Դϴ�.
					// �������� ���� �ʽ��ϴ�.

	std::pair<int, double> p5; // �翬�� ���ڵ�� �����մϴ�.	
}


