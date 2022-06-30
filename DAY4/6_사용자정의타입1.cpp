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
	// 핵심 : 디폴트 생성자가 없는 타입을 컨테이너에 저장하기. !
	std::vector<Point> v1;    // ok
	std::vector<Point> v2(3); // error. Point 는 디폴트 생성자가 없습니다.

	std::vector<Point> v3 = { Point(0,0), Point(0,0), Point(0,0) };//ok

	Point pt(0, 0);
	std::vector<Point> v4(3, pt); // ok. pt를 복사해서 3개 만들어 달라


	// 디폴트 생성자가 없는 경우. resize 도 주의 하세요
	
//	v3.resize(10); // error. 새로 추가된 7개도 생성자 호출해야 하는데
					//		 디폴트 생성자가 없습니다.
	v3.resize(10, pt); // ok

	
}



