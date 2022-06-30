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
};

int main()
{
	std::vector<Point*> v; // vector�� ������ ����

	v.push_back(new Point(1, 2));
	v.push_back(new Point(3, 1));
	v.push_back(new Point(4, 2));
	v.push_back(new Point(2, 2));

	// v�� sort �� ������.. �� ��å�� "����ǥ����" ���

//	std::sort(v.begin(), v.end());	// ������ ������
									// �������� �߸��� �ڵ�
									// ��ü�� ���·� ������ �ʰ�, �ּҷ� ��

	// �Ʒ� ó�� �� ��å �����ؾ� �մϴ�.
	std::sort(v.begin(), v.end(),
		[](const Point* p1, const Point* p2) { return p1->x < p2->x; });

	for (auto p : v) 
		p->dump();

	for (auto p : v) delete p;

}




