#include "show.h"
#include <set>

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

struct ComparePoint
{
	inline bool operator()(const Point& p1, const Point& p2) const
	{
		return p1.x < p2.x;
	}
};

int main()
{
	std::set<Point, ComparePoint> s;

	s.emplace(5, 5);
	s.emplace(3, 2);
	s.emplace(2, 1);
	s.emplace(1, 5);

	// �Ʒ� ������ ��?? ������ ���� ������� ? 
	// => �˻� �Ҷ� ���ٴ� ���� ��� �����ұ�� ?
	// => ���� �ڵ�� Point(3,2) == Point(3,2) ó�� "==" ���� �ȵ˴ϴ�.

	// �Ʒ� �ڵ�� "���Լ���ü"�� ����ؼ� "ũ���� �ʰ� ������ ���� ���"�� ã���ϴ�.
	// => equivalent(���) �˻� �Դϴ�.
	auto ret1 = s.find(Point(3, 1));	// if (���Լ�(root, ���) )
										//    �������� �̵�
										// else if( ���Լ�(���, root))
										//    ���������� �̵�
										// else
										//		ã�Ҵ�.
	std::cout << ret1->x << ",  " << ret1->y << std::endl; 
							// 3, 2


//	auto ret2 = std::find(s.begin(), s.end(), Point(3, 2));
}










