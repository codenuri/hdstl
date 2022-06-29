#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

// capacity ���� - vector ���� �ִ� �����Դϴ�.

int main()
{
	std::vector<int> v(10, 0);

	v.resize(7); // ��� ����������� ?

	std::cout << v.size()     << std::endl; // 7
	std::cout << v.capacity() << std::endl; // 10(�޸� ��뷮)


	v.push_back(3); // ���� �Ѱ�(3) �߰�
					// ���� ���°� capacity > size �̹Ƿ�
					// �� ������ "not expensive" �մϴ�.

	std::cout << v.size() << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 10

	v.shrink_to_fit(); // ������ �޸𸮴� �ʿ����.
						// 8�� �޸� ���Ҵ��ؼ� ���� ������ ���

	std::cout << v.size() << std::endl;     // 8
	std::cout << v.capacity() << std::endl; // 8


	v.push_back(3); // ���� �Ѱ� �߰�
					// ���� ��Ȳ�� capacity == size �Դϴ�.
					// ��, ���� ������ �����Ƿ� �޸� ���Ҵ� �ʿ�
					// �� ������ "expensive" �մϴ�.

	std::cout << v.size() << std::endl;     // 9
	std::cout << v.capacity() << std::endl; // 12(vc++, ���� �޸� ũ�� 1.5��)
											// 16(g++,  ���� �޸� ũ�� 2��)

	std::vector<int> v2; // size = 0, capacity = 0
//	v2.resize(20);		// size = 20, capacity = 20
	v2.reserve(20);		// size = 0,  capacity = 20

	v2.push_back(1); // 20���� ������ ������ �޸� ���Ҵ� �����Ƿ� 
					 // ������ �����մϴ�.
}
// ���̽� ����.. ����Ʈ�� C++�� vector �Դϴ�.
// s = [1,2,3] // �����޸𸮴� 3�� ���ƴ� 4�� �Ҵ��մϴ�.
// s.append(4) // ���������� �����Ƿ� �޸� ���Ҵ� �����Ƿ� �����ϴ�.
// s.append(5) // 5���� �ƴ϶� 8���� �޸𸮷� ���Ҵ� �˴ϴ�.






