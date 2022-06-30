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

	// ���2. �ӽð�ü(rvalue��) �ֱ�
//	v.push_back( Point(1, 2) );





	// ��� 3. ��ü�� ���� �������� ����
	// ��ü�� ���鶧 ����� ������ ���ڸ� �����ϴ°���
	// ȿ�����Դϴ�.
	v.emplace_back(1, 2);
			// vector �� ���������� 
			// ���ۿ� Point �� ���鶧 1,2�� ���

	
	// ��� 
	// vector<int> v1;
	// => �׳� push_back ���� ��������. v1.push_back(10)
	// => emplace_back �ص� ���� ������ �ʽ��ϴ�. ���� ����.. 

	// vector<Point> v2; ��, ����� Ÿ���� �����Ҷ�
	// => push_xxx() �迭 �Լ� ���, emplace_xxx() ����ϼ���
	// => v2.emplace_back(1,2); 1,2 �� ������ ����

	// push_back  => emplace_back
	// push_front => emplace_front
	// insert     => emplace

	// emplace_xxx �� C++11 ���� �˴ϴ�.
	// => emplace_xxx �Լ��� ���鶧�� "�Ϻ�������"�̶�� ����� �־�� �մϴ�.
	// => �� ����� "C++11" ���� ���Խ��ϴ�.

	std::cout << "------------------" << std::endl;	
}

// emplace�� R-value�� �����ϰ��� �ϴ� ��쿡�� �����ϰڳ׿�?  
// => ��.. ��ü�� �����Ŀ� �ٸ� �뵵�� ����� �����Ҷ��� 
// => push_xx ���ϼ���
// // 
// �׷��� ������ shared_ptr�� ���� ���� �������� �ʳ���?
// => vector<���������Ÿ��������*>, vector<����Ʈ������>, 
// => push_xxx() ����ϸ� �˴ϴ�.
// => ����Ʈ������ �Ҷ� �ٷ�� �˴ϴ�.




