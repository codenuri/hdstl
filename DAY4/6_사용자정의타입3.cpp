
#include <vector>
#include <algorithm>
#include "show.h"
class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}
	~Point() { std::cout << "~Point()" << std::endl; }

	Point(const Point& p)
	{
		std::cout << "Point(const Point&)" << std::endl;
	}
	void dump() const 
	{
		std::cout << x << ", " << y << std::endl;
	}
	inline bool operator<(const Point& pt) const
	{
		return x < pt.x;
	}
};
int main()
{
	std::vector<Point> v;

	v.emplace_back(1, 2); // Point(1,2) �� ���� ���Դϴ�.
	v.emplace_back(2, 3);
	v.emplace_back(3, 2);
	v.emplace_back(0, 1);

	// �����̳ʿ� ����� ���� Ÿ���� �ִ� ���� �����մϴ�

	// �׷���, �پ��� �˰��� �Լ��� ����Ϸ��� 
	// �ش� �˰����� �䱸�ϴ� ������ �����ؾ� �մϴ�.
	// std::sort �� �Ϸ��� vector �� �����ϴ� ��ҿ� ���� ũ�� �񱳰� �����ؾ� �մϴ�.
//	std::sort(std::begin(v), std::end(v));

	// ��� 1. sort�� 3��° ���ڷ� ũ�� �񱳸� �ϴ� ����ǥ���� ����
	std::sort(v.begin(), v.end(),
		[](const Point& p1, const Point& p2) { return p1.x < p2.x; } );

	// ��� 2. Point Ŭ���� ��ü�� < ������ �����ϵ���
	//        ������ ������ �Լ� ����
	std::sort(v.begin(), v.end()); // < ������ �Լ��� �����ߴٸ� ok. 
}
// ����� ���� Ÿ�Կ� ���ؼ� "��" �����ϰ� �Ϸ���
// 6���� ���迬���ڸ� ��� �����ϴ� ���� ��Ģ �Դϴ�
// => ==, !=, <, >, <=, >=
// => �׷���, �׻� 6���� ����� ���� �ʹ� ������(boiler plate) �۾� �Դϴ�.


// C++20 ���� ���ο� �� �����ڰ� ���Խ��ϴ�.(���ּ� ������)
// auto b = p1 <=> p2;
// operator<=>() �Լ� �Ѱ��� ����� 6���� �ڵ����� ���� �˴ϴ�.




