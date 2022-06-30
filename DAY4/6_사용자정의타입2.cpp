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

	// ������ ������ ������
	// 1. ��ü�� ������ �ֱ�.

//	Point pt(1, 2);
	
//	v.push_back(pt); // �̼��� pt ��ü�� �����Ǵ� ���� �ƴ϶�
				     // ���� ���ο� ��ü�� ����µ�, pt�� �����ؼ� ����Ե˴ϴ�.


	// ��� 2. ��ü�� ���� �������� ����
	// ��ü�� ���鶧 ����� ������ ���ڸ� �����ϴ°���
	// ȿ�����Դϴ�.
	v.emplace_back(1, 2);
			// vector �� ���������� 
			// ���ۿ� Point �� ���鶧 1,2�� ���

	
	// ��� 
	// vector<int> v1;
	// => �׳� push_back ���� ��������. v1.push_back(10)

	// vector<Point> v2; ��, ����� Ÿ���� �����Ҷ�
	// => push_xxx() �迭 �Լ� ���, emplace_xxx() ����ϼ���
	// => v2.emplace_back(1,2); 1,2 �� ������ ����

	// push_back  => emplace_back
	// push_front => emplace_front
	// insert     => emplace


	std::cout << "------------------" << std::endl;	
}



