// 6_사용자정의타입0
#include <vector>
#include "show.h"

class Point
{
	int x, y;
public:
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// primitive 타입을 저장하는 컨테이너
	std::vector<int> v1(10); 

	// user define type 을 저장하는 컨테이너
	// 아래 2개 꼭 구별하세요
	std::vector<Point> v2 = { Point(1,1), Point(2,2) };
	std::vector<Point*> v3 = { new Point(1,1), new Point(2,2) };

}



