#include <iostream>


class URandom
{

public:
	int operator()()
	{
		return rand() % 10;
	}
};
URandom urand; // ��ü���� ()�����ڰ� ������ �Ǿ� �����Ƿ� �Լ�ó�� ��밡��

int main()
{
	for (int i = 0; i < 10; i++)
		std::cout << urand() << std::endl;
}





