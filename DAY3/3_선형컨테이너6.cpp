#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>
#include "show.h"

// Ȱ�� ���� �Դϴ�.

class FindChar
{
	std::string data;
public:
	FindChar(const std::string& s) : data(s) {}

	inline bool operator()(char c) const  // <== ���� const �� ��� �Ǵµ�
	{									  // ������ �� �����ϴ�. 
										  // ��� ����Լ� ��� ������ ã�ƺ�����
		return std::find(data.begin(), data.end(), c) != data.end();
	}
};









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
//		std::replace(e.begin(), e.end(), 'i', ' ');

		// �� ������ ���� �ؼ�, "��� ����"�� �������� ġȯ�� ������.
		// => �ּ��� �ڵ带 ������ ������..
//		std::replace_if(e.begin(), e.end(), 
//			[](char c) { return c == 'a' || c == 'i';  }, ' ');


		FindChar fc("aeiouAEIOU");
//		FindChar fc("0123456789");

//		bool b = fc('a');

		std::replace_if(e.begin(), e.end(), fc, ' ');

	}



	//-------------------------------------
	for (auto& n : v)
		std::cout << n << std::endl;
}


