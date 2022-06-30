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
	// std::vector<Point>  : Point ��ü�� ����
	// std::vector<Point*> : Point ��ü�� �ּҸ� ����

	std::vector<Point>  v2 = { Point(1,1), Point(2,2) };
//	std::vector<Point*> v3 = { new Point(1,1), new Point(2,2) };
	std::vector<Point*> v3(2);

	v3[0] = new Point(1, 1);
	v3[1] = new Point(2, 2);

//	Point pt;
//	v3[1] = &pt; // �̷��Ե� �����մϴ�.

	// �ٽ� : ����ڰ� new �� ��ü�� ����ڰ� delete �ؾ� �մϴ�.
	// v3�� ��� ��ü�� ����ڰ� new�� ������ٸ� v3 �ı����� ��� delete
	// �ؾ� �մϴ�.
	for (auto p : v3)
		delete p;
}







