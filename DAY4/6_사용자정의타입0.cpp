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
	// std::vector<Point>  : Point 객체를 보관
	// std::vector<Point*> : Point 객체의 주소를 보관

	std::vector<Point>  v2 = { Point(1,1), Point(2,2) };
//	std::vector<Point*> v3 = { new Point(1,1), new Point(2,2) };
	std::vector<Point*> v3(2);

	v3[0] = new Point(1, 1);
	v3[1] = new Point(2, 2);

//	Point pt;
//	v3[1] = &pt; // 이렇게도 가능합니다.

	// 핵심 : 사용자가 new 한 객체는 사용자가 delete 해야 합니다.
	// v3의 모든 객체를 사용자가 new로 만들었다면 v3 파괴전에 모두 delete
	// 해야 합니다.
	for (auto p : v3)
		delete p;
}







