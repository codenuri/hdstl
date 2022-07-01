#include <memory>
#include <iostream>

int main()
{
	// 자원을 독점하는 스마트 포인터
	std::unique_ptr<int> up1(new int);
	std::unique_ptr<int> up2 = up1; // error. 자원 공유 안됩니다.
	std::unique_ptr<int> up3 = std::move(up1); // ok..  자원 이동은 가능

	// unique_ptr 은 오버헤드가 거의 없습니다.
	// "raw pointer" 를 사용하는 것과 거의 동일합니다.
	std::cout << sizeof(up1) << std::endl;
}
// std::shared_ptr : 자원을 공유 가능한 스마트 포인터
// std::unique_ptr : 자원을 독점하는 스마트 포인터
// std::weak_ptr   : 자원의 소유권이 없는 스마트 포인터
//					(상호 참조 문제의 대한 해결)