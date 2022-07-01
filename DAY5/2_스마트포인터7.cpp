#include "show.h"
#include <memory>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	std::shared_ptr<People> bf; // best friend
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	std::shared_ptr<People> sp2(new People("lee"));

	// 아래 코드가 있으면 객체가 delete 되지 않습니다.
	// 메모리 누수 입니다.
	// 이런 현상을 "상호 참조" 또는 "순환참조" 또는 "원형 참조" 라고 합니다.
	sp1->bf = sp2;
	sp2->bf = sp1;
}


