// ��ƿ��Ƽ2-1
#include <tuple>
#include <list>
#include <iostream>

// tuple vs struct
// �Լ����� �簢���� ��ȯ�ϰ� �ʹ�.
// => �簢���� ��Ȯ �մϴ�. "Ÿ�� ����"�� ���� ������� ?
struct Rect
{
};
Rect f1() { Rect r; return r; }

// �Լ����� ������ ���� 3�� ��ȯ�Ϸ��� �մϴ�.(������ ����..)
std::tuple<int, int, int> f2()
{
	return std::make_tuple<int, int, int>(1, 2, 3);
}

int main()
{
	std::list<std::tuple<int, double>> s;
	s.push_back(std::make_tuple(1, 1.1));
	s.push_back(std::make_tuple(2, 2.2));
	s.push_back(std::make_tuple(3, 3.3));

	auto p = s.begin(); 
	
	// �ݺ��ڴ� "��Ҹ� ����Ű�� ������" ��� �����ϼ���. ��
	// p = std::tuple<int, double>*
	// *p = std::tuple<int, double>
	int n = std::get<0>(*p); // 1
	double d = std::get<1>(*p); // 1.1

}