#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
	// pair �� �����ϴ� hash �Դϴ�.
	std::unordered_map<std::string, std::string> m;

	m["mon"] = "������";

	auto p = m.begin();

	std::cout << p->first << std::endl;
	std::cout << p->second << std::endl;
}

// �Է� ������� (= ����) ������� �ʾҴ��� �ǹ̰� unordered �ΰ���? 
// => �Է¼����Ӿƴ϶�, � ����(ũ��)���ε� ���ĵ��� �ʾҴ��Դϴ�.

// std::set �� �Է� ������ �ƴ�, ũ��(std::less) �� ���� �Ǿ����ϴ�.


