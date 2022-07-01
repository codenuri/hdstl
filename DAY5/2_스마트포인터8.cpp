#include "show.h"
#include <memory>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

//	std::shared_ptr<People> bf; // 참조계수가 증가

	People* bf; // raw pointer 는 객체를 가리킬수 있다.
				// 하지만, 참조계수는 증가하지 않는다.
};
/*
int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	std::shared_ptr<People> sp2(new People("lee"));

	sp1->bf = sp2.get();
	sp2->bf = sp1.get();
}
*/
// raw pointer 사용시 아래의 문제점이 있습니다.
int main()
{
	std::shared_ptr<People> sp1(new People("kim"));

	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2.get();
		sp2->bf = sp1.get();
	
	}// <= 이순간 "lee" 객체는 파괴됩니다.
	 // <= 그런데, "lee" 를 가리키던 sp1->bf 는 계속 메모리 주소를 가지고 
	 //    있습니다.

	// 아래 처럼 조사하면 "0" 은 아니지만 이미 파괴되고 없는 메모리 주소입니다.
	// => "Dangling pointer" 라고 합니다.
	if (sp1->bf != 0)
	{
		auto s = sp1->bf->name;
	}
}

