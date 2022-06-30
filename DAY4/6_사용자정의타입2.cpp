#include <vector>
#include "show.h"

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) 
	{
		std::cout << "Point()" << std::endl;
	}
	~Point() { std::cout << "~Point()" << std::endl; }
	
	Point(const Point& p)
	{
		std::cout << "Point(const Point&)" << std::endl;
	}
};
int main()
{
	std::vector<Point> v;

	// 실행결과 예측해 보세요
	// 1. 객체를 생성후 넣기.

//	Point pt(1, 2);
	
//	v.push_back(pt); // 이순간 pt 자체가 보관되는 것이 아니라
				     // 힙에 새로운 객체를 만드는데, pt를 복사해서 만들게됩니다.


	// 방법 2. 객체를 만들어서 전달하지 말고
	// 객체를 만들때 사용할 생성자 인자를 전달하는것이
	// 효율적입니다.
	v.emplace_back(1, 2);
			// vector 가 내부적으로 
			// 버퍼에 Point 를 만들때 1,2를 사용

	
	// 결론 
	// vector<int> v1;
	// => 그냥 push_back 으로 넣으세요. v1.push_back(10)

	// vector<Point> v2; 즉, 사용자 타입을 저장할때
	// => push_xxx() 계열 함수 대신, emplace_xxx() 사용하세요
	// => v2.emplace_back(1,2); 1,2 는 생성자 인자

	// push_back  => emplace_back
	// push_front => emplace_front
	// insert     => emplace


	std::cout << "------------------" << std::endl;	
}



