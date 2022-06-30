#include <vector>
#include "show.h"

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	std::vector<Point> v1;    // ok
	std::vector<Point> v2(3); // error. Point 는 디폴트 생성자가 없습니다.
	std::vector<Point> v3 = { Point(0,0), Point(0,0), Point(0,0) };//ok

	Point pt(0, 0);
	std::vector<Point> v4(3, pt); // ok. pt를 복사해서 3개 만들어 달라


	
}



