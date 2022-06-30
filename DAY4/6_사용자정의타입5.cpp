#include "show.h"
#include <set>

// C++ 표준의 less 는 아래와 같습니다.
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

// Point 타입의 객체 2개를 크기 비교하는 함수 객체
struct ComparePoint
{
	inline bool operator()(const Point& p1, const Point& p2) const
	{
		return p1.x < p2.x;
	}
};

int main()
{
	// 사용자 정의 타입을 "set"에 보관하려면 크기 비교가 되어야 합니다.
//	std::set<Point> s;
//	std::set<Point, std::less<Point>, std::allocator<Point> > s;

	// 해결책 1. Point 타입안에 "operator<" 연산자를 제공하고, 그냥 아래처럼 사용
//	std::set<Point> s;

	// 해결책 2. 비교 객체를 "less<>" 를 사용하지 말고 사용자가 만든것으로 교체
	std::set<Point, ComparePoint> s;


	s.emplace(5, 5); 
	s.emplace(3, 2);
	s.emplace(2, 1);
	s.emplace(1, 5);




	// 아래 2줄을 잘 생각해 보세요 - 중요합니다.!
	// equality, Equivalency

//	auto ret1 = s.find(Point(3, 2));
//	auto ret2 = std::find(s.begin(), s.end(), Point(3, 2));
}










