#include <iostream>


class URandom
{

public:
	int operator()()
	{
		return rand() % 10;
	}
};
URandom urand; // 객체지만 ()연산자가 재정의 되어 있으므로 함수처럼 사용가능

int main()
{
	for (int i = 0; i < 10; i++)
		std::cout << urand() << std::endl;
}





