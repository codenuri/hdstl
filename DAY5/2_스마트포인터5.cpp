#include <iostream>
#include <memory>

void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	// �Ʒ� �ڵ�� ���� �޸� �Ҵ��� ����ϰ� �ɱ�� ? - 2��
	// 1. new Point(1,2);
	// 2. new ������ü(������� + ��� �߰�����) : 20~30����Ʈ����ũ��

	// �Ʒ� �ڵ�� "Point ��ü ����" �� "������ü����" �� ���� ���� �ϰ� �˴ϴ�.
//	std::shared_ptr<Point> sp(new Point(1, 2));

	// �Ʒ� �ڵ�� "Point ��üũ�� + ������ü ũ��" �� �޸𸮸� �ѹ��� �Ҵ��մϴ�.
	// 1. "Point ��üũ�� + ������ü ũ��" �� �޸� �Ҵ���
	// 2. shared_ptr �� ���� ��ȯ
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);
							//  std::make_shared<Ÿ��>(���������ڰ�);

	// std::make_shared �� ����
	// 1. ��ü�� ������ü�� �޸𸮸� �ѹ��� �Ҵ��ؼ� ȿ���� �޸� ����
	// 2. exception safety ���� ( �ڿ� ���� ���� ����)

	foo( std::shared_ptr<int>(new int), goo() );			
	
}

void foo( std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }

