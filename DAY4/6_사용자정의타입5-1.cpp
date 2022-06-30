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
	// => 현재 코드는 Point(3,2) == Point(3,2) 처럼 "==" 연산 안됩니다.

	// 아래 코드는 "비교함수객체"를 사용해서 "크지도 않고 작지도 않은 요소"를 찾습니다.
	// => equivalent(동등성) 검색 입니다.
	auto ret1 = s.find(Point(3, 1));	// if (비교함수(root, 요소) )
										//    왼쪽으로 이동
										// else if( 비교함수(요소, root))
										//    오른쪽으로 이동
										// else
										//		찾았다.
	std::cout << ret1->x << ",  " << ret1->y << std::endl; 
							// 3, 2


//	auto ret2 = std::find(s.begin(), s.end(), Point(3, 2));
}










