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

	// 아래 한줄은 왜?? 에러가 나지 않을까요 ? 
	// => 검색 할때 같다는 것을 어떻게 결정할까요 ?
	auto ret1 = s.find(Point(3, 2));


//	auto ret2 = std::find(s.begin(), s.end(), Point(3, 2));
}










