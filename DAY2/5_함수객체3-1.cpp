#include <iostream>
#include <bitset>   // ��Ʈ ������ ���� STL�� �����ϴ� Ŭ����

class URandom
{
//	bool history[1000]; // 1000 byte �޸� ���=> �־�
						// 1000 bit �� �˴ϴ�.

	std::bitset<10> bs;	// 10��Ʈ ����
	bool recycle;
public:
	URandom(bool b = false) : recycle(b) 
	{
//		bs.set(5); // 5��° ��Ʈ�� 1��
		bs.set();  // ��� ��Ʈ�� 1��
	}

	int operator()()
	{
		if (bs.none()) // ��� ��Ʈ�� 0(���̻� ���ο� ������ ���ٸ�)
		{
			if (recycle == true) // �����Ѵٰ� ������
				bs.set();   // �ٽ� ��� 1��
			else
				return -1;  // ���̻� ���� ����.
		}
		int k = 0;
		while ( ! bs.test( k = rand() % 10) );
		bs.reset(k);


		return k;
	}

	// ����ڰ� ���ϵ��� ��� ����Լ� ������ �ּ���
	void reset() { bs.set(); } // �ٽ� 1�� ����
	int count() { return bs.count(); } // ��밡���� ������ ����
};

//URandom urand; 
URandom urand(true);

int main()
{
	for (int i = 0; i < 5; i++)
		std::cout << urand() << std::endl;
	
	std::cout << urand.count() << std::endl; // ������ 5�� �� ��밡��
}





