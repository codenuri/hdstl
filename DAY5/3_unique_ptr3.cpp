#include <memory>
#include <iostream>

struct Freer
{
	void operator()(void* p)
	{
		free(p);
	}
};

int main()
{
	// ������ ����
	// shared_ptr : �������� 2��° ���ڷ� ����
	// unique_ptr : ���ø� 2��° ���ڷ� �Լ� ��ü ����
	std::shared_ptr<int> sp(static_cast<int*>(malloc(sizeof(int)), free);
	std::unique_ptr<int, Freer> up(static_cast<int*>(malloc(sizeof(int)));


	// shared_ptr vs unique_ptr






	std::unique_ptr<int> up1(new int);
	std::unique_ptr<int> up2(new int[10]);
}