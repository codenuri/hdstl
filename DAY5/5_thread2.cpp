#include <iostream>
#include <thread> 

void foo(int n, double d)
{
	std::cout << "foo" << std::endl;
}

class Test
{
public:
	void goo(int n, double d)
	{
		std::cout << "goo" << std::endl;
	}
};

int main()
{
	// �ٽ� 1. �����带 �����ؼ� ���ϴ� �Լ��� �����ϴ� ���
	// C����� ������    : �ݵ�� ������ �Լ��� void* �� ���ڷ� �޾ƾ� �Ѵ�.
	// STL std::thread : � ����� �Լ��� ������� ���డ��

	std::thread t1(&foo, 1, 3.4); // ������ ������. 

	// �ٽ� 2. �����带 ������ ���, �ݵ�� �Ʒ� 2�����Ѱ��� �ؾ� �մϴ�.
	t1.join();   // ������ ����� ���� ���
//	t1.detach(); // ������ �ڵ� ���� ����(�ڽ� ������� �и��ϰڴ�.)

	// �ٽ� 3. ��� �Լ��� ������� ���డ���մϴ�.
	Test test;

	std::thread t2(&Test::goo, &test, 1, 3.4); // ��� �Լ� ����
						// => ���ο� �����尡 test.goo(1,3.4) ����
	t2.join();
}


