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
	// �ٽ� : ����Ʈ �����ڰ� ���� Ÿ���� �����̳ʿ� �����ϱ�. !
	std::vector<Point> v1;    // ok
	std::vector<Point> v2(3); // error. Point �� ����Ʈ �����ڰ� �����ϴ�.

	std::vector<Point> v3 = { Point(0,0), Point(0,0), Point(0,0) };//ok

	Point pt(0, 0);
	std::vector<Point> v4(3, pt); // ok. pt�� �����ؼ� 3�� ����� �޶�


	// ����Ʈ �����ڰ� ���� ���. resize �� ���� �ϼ���
	
//	v3.resize(10); // error. ���� �߰��� 7���� ������ ȣ���ؾ� �ϴµ�
					//		 ����Ʈ �����ڰ� �����ϴ�.
	v3.resize(10, pt); // ok

	
}



