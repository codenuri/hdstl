#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>
#include "show.h"

// Ȱ�� ���� �Դϴ�.
int main()
{
	std::vector<std::string> v;
	std::ifstream f("3_���������̳�6.cpp"); // ���� �����̸�

	std::string s;

//	f >> s;				// ���Ͽ��� �� �ܾ� �б�
//	std::getline(f, s); // ���Ͽ��� �� ��(����) �б�

	// ���Ͽ��� ���پ� �о vector�� ����
	while (std::getline(f, s))
		v.push_back(s);
	//----------------------------
//	std::reverse(v.begin(), v.end());

	// v[0] �� 1��° ����ε�, 1��° ����� Ÿ���� std::string �̹Ƿ�
	// string�� begin, end �ֽ��ϴ�.
//	std::reverse(v[0].begin(), v[0].end());

	for (auto& e : v)
	{
//		std::reverse(e.begin(), e.end());

		// 'i' ���ڸ� �������� ġȯ�� �޶�
		std::replace(e.begin(), e.end(), 'i', ' ');

		// �� ������ ���� �ؼ�, "��� ����"�� �������� ġȯ�� ������.
		// => �ּ��� �ڵ带 ������ ������..
	}



	//-------------------------------------
	for (auto& n : v)
		std::cout << n << std::endl;
}


