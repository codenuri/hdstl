#include <thread>
#include <future>
#include <chrono>
#include <iostream>
using namespace std::literals;

int foo()
{
	std::this_thread::sleep_for(5s);

	return 100;
}

int main()
{
	// async�� ������ �Լ�(������)�� ����� ������ �ƴ�
	// �̷��� ������ �ְ� �˴ϴ�.
	std::future<int> ft = std::async(std::launch::async, &foo); // foo�� �񵿱�(������)�� ������ �޶�
				
	// ft�� �ϳ��� �����常 ��� �����մϴ�.
	// �ǵ��� ������� ft�� ������ �����ϴ�. �������� �Ʒ�ó���ϼ���
	std::shared_future<int> ft2 = ft.share();

	// ft2�� �ٸ� ������� ������ ��� ���ѵ� �˴ϴ�


	std::cout << "main ������ ��� ����" << std::endl;

	// ���� foo�� ����� �ʿ��ϸ� �Ʒ� ó�� �����ϴ�.
	int n = ft.get();  // �� ���� �����尡 ��ȯ�Ҷ� ���� ��� �մϴ�.
			

	std::cout << n << std::endl;
}




/*
int main()
{
	// �Ʒ� ó�� ���� �����带 �����ϸ� ������ �Լ��� ��ȯ����
	// ��� ���� ������ ���ϴ�.(�����尣 ����� ���� ����)
	std::thread t1(&foo);
	t1.join();
}
*/