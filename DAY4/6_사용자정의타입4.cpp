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
	std::vector<Point*> v; // vector에 포인터 보관

	v.push_back(new Point(1, 2));
	v.push_back(new Point(3, 1));
	v.push_back(new Point(4, 2));
	v.push_back(new Point(2, 2));

	// v를 sort 해 보세요.. 비교 정책은 "람다표현식" 사용

//	std::sort(v.begin(), v.end());	// 에러는 없지만
									// 논리적으로 잘못된 코드
									// 객체의 상태로 비교하지 않고, 주소로 비교

	// 아래 처럼 비교 정책 전달해야 합니다.
	std::sort(v.begin(), v.end(),
		[](const Point* p1, const Point* p2) { return p1->x < p2->x; });

	for (auto p : v) 
		p->dump();

	for (auto p : v) delete p;

}




