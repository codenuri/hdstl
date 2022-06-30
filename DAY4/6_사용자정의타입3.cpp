
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
	inline bool operator<(const Point& pt) const
	{
		return x < pt.x;
	}
};
int main()
{
	std::vector<Point> v;

	v.emplace_back(1, 2); // Point(1,2) 를 넣은 것입니다.
	v.emplace_back(2, 3);
	v.emplace_back(3, 2);
	v.emplace_back(0, 1);

	// 컨테이너에 사용자 정의 타입을 넣는 것은 간단합니다

	// 그런데, 다양한 알고리즘 함수를 사용하려면 
	// 해당 알고리즘이 요구하는 연산을 지원해야 합니다.
	// std::sort 를 하려면 vector 가 저장하는 요소에 대한 크기 비교가 가능해야 합니다.
//	std::sort(std::begin(v), std::end(v));

	// 방법 1. sort의 3번째 인자로 크기 비교를 하는 람다표현식 전달
	std::sort(v.begin(), v.end(),
		[](const Point& p1, const Point& p2) { return p1.x < p2.x; } );

	// 방법 2. Point 클래스 자체에 < 연산이 가능하도록
	//        연산자 재정의 함수 제공
	std::sort(v.begin(), v.end()); // < 연산자 함수를 제공했다면 ok. 
}
// 사용자 정의 타입에 대해서 "비교" 가능하게 하려면
// 6개의 관계연산자를 모두 제공하는 것이 원칙 입니다
// => ==, !=, <, >, <=, >=
// => 그런데, 항상 6개를 만드는 것은 너무 지루한(boiler plate) 작업 입니다.


// C++20 에서 새로운 비교 연산자가 나왔습니다.(우주선 연산자)
// auto b = p1 <=> p2;
// operator<=>() 함수 한개만 만들면 6개가 자동으로 지원 됩니다.




