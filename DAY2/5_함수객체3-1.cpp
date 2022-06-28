#include <iostream>
#include <bitset>   // 비트 관리를 위한 STL이 제공하는 클래스

class URandom
{
	std::bitset<10> bs;
	bool recycle;
public:
	URandom(bool b = false) : recycle(b) 
	{
//		bs.set(5); // 5번째 비트만 1로
		bs.set();  // 모든 비트를 1로
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





