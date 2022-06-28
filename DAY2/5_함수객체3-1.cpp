#include <iostream>
#include <bitset>   // 비트 관리를 위한 STL이 제공하는 클래스

class URandom
{
//	bool history[1000]; // 1000 byte 메모리 사용=> 최악
						// 1000 bit 면 됩니다.

	std::bitset<10> bs;	// 10비트 관리
	bool recycle;
public:
	URandom(bool b = false) : recycle(b) 
	{
//		bs.set(5); // 5번째 비트만 1로
		bs.set();  // 모든 비트를 1로
	}

	int operator()()
	{
		if (bs.none()) // 모든 비트가 0(더이상 새로운 난수가 없다면)
		{
			if (recycle == true) // 재사용한다고 했으면
				bs.set();   // 다시 모두 1로
			else
				return -1;  // 더이상 난수 없음.
		}
		int k = 0;
		while ( ! bs.test( k = rand() % 10) );
		bs.reset(k);


		return k;
	}

	// 사용자가 편리하도록 몇가지 멤버함수 제공해 주세요
	void reset() { bs.set(); } // 다시 1로 놓고
	int count() { return bs.count(); } // 사용가능한 난수의 갯수
};

//URandom urand; 
URandom urand(true);

int main()
{
	for (int i = 0; i < 5; i++)
		std::cout << urand() << std::endl;
	
	std::cout << urand.count() << std::endl; // 앞으로 5개 더 사용가능
}





