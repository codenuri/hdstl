// 6_���������Ÿ��0
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
	// primitive Ÿ���� �����ϴ� �����̳�
	std::vector<int> v1(10); 

	// user define type �� �����ϴ� �����̳�
	// �Ʒ� 2�� �� �����ϼ���
	std::vector<Point> v2 = { Point(1,1), Point(2,2) };
	std::vector<Point*> v3 = { new Point(1,1), new Point(2,2) };

}



