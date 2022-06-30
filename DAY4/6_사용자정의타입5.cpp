#include "show.h"
#include <set>

// C++ ǥ���� less �� �Ʒ��� �����ϴ�.
/*
template<typename T>
struct less
{
	inline bool operator()(const T& a, const T& b) const
	{
		return a < b;
	}
};
*/
//-------------------------------------------------------------------

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

// Point Ÿ���� ��ü 2���� ũ�� ���ϴ� �Լ� ��ü
struct ComparePoint
{
	inline bool operator()(const Point& p1, const Point& p2) const
	{
		return p1.x < p2.x;
	}
};

int main()
{
	// ����� ���� Ÿ���� "set"�� �����Ϸ��� ũ�� �񱳰� �Ǿ�� �մϴ�.
//	std::set<Point> s;
//	std::set<Point, std::less<Point>, std::allocator<Point> > s;

	// �ذ�å 1. Point Ÿ�Ծȿ� "operator<" �����ڸ� �����ϰ�, �׳� �Ʒ�ó�� ���
//	std::set<Point> s;

	// �ذ�å 2. �� ��ü�� "less<>" �� ������� ���� ����ڰ� ��������� ��ü
	std::set<Point, ComparePoint> s;


	s.emplace(5, 5); 
	s.emplace(3, 2);
	s.emplace(2, 1);
	s.emplace(1, 5);




	// �Ʒ� 2���� �� ������ ������ - �߿��մϴ�.!
	// equality, Equivalency

//	auto ret1 = s.find(Point(3, 2));
//	auto ret2 = std::find(s.begin(), s.end(), Point(3, 2));
}










