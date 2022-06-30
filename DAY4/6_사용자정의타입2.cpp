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

	// 방법2. 임시객체(rvalue로) 넣기
//	v.push_back( Point(1, 2) );





	// 방법 3. 객체를 만들어서 전달하지 말고
	// 객체를 만들때 사용할 생성자 인자를 전달하는것이
	// 효율적입니다.
	v.emplace_back(1, 2);
			// vector 가 내부적으로 
			// 버퍼에 Point 를 만들때 1,2를 사용

	
	// 결론 
	// vector<int> v1;
	// => 그냥 push_back 으로 넣으세요. v1.push_back(10)
	// => emplace_back 해도 전혀 나쁘지 않습니다. 동일 성능.. 

	// vector<Point> v2; 즉, 사용자 타입을 저장할때
	// => push_xxx() 계열 함수 대신, emplace_xxx() 사용하세요
	// => v2.emplace_back(1,2); 1,2 는 생성자 인자

	// push_back  => emplace_back
	// push_front => emplace_front
	// insert     => emplace

	// emplace_xxx 는 C++11 부터 됩니다.
	// => emplace_xxx 함수를 만들때는 "완벽한전달"이라는 기술이 있어야 합니다.
	// => 이 기술이 "C++11" 에서 나왔습니다.

	std::cout << "------------------" << std::endl;	
}

// emplace는 R-value를 저장하고자 하는 경우에만 유용하겠네요?  
// => 네.. 객체를 만든후에 다른 용도로 사용후 저장할때는 
// => push_xx 로하세요
// // 
// 그런데 요즘은 shared_ptr을 보통 많이 저장하지 않나요?
// => vector<사용자정의타입포인터*>, vector<스마트포인터>, 
// => push_xxx() 사용하면 됩니다.
// => 스마트포인터 할때 다루게 됩니다.




