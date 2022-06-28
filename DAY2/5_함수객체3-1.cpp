#include <iostream>
#include <bitset>   // ��Ʈ ������ ���� STL�� �����ϴ� Ŭ����

class URandom
{
	std::bitset<10> bs;
	bool recycle;
public:
	URandom(bool b = false) : recycle(b) 
	{
//		bs.set(5); // 5��° ��Ʈ�� 1��
		bs.set();  // ��� ��Ʈ�� 1��
	}

	int operator()()
	{
		return rand() % 10;
	}
};
URandom urand; 


int main()
{
	for (int i = 0; i < 10; i++)
		std::cout << urand() << std::endl;
	
}





