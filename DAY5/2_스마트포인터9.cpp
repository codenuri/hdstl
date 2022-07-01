#include "show.h"
#include <memory>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	//	std::shared_ptr<People> bf; // 참조계수가 증가

//	People* bf; // raw pointer 는 객체를 가리킬수 있다.
				// 하지만, 참조계수는 증가하지 않는다.	
				// 그런데, 가리키던 곳의 객체가 파괴되었는지 조사를 못합니다
				// "Dangling pointer" 의 위험이 있습니다.

	std::weak_ptr<People> bf;	// 참조계수 증가 안함
								// 객체 파괴 조사 가능
								// Dangling pointer 발생 안됨 
};
int main()
{
	std::shared_ptr<People> sp1(new People("kim"));

	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2;
		sp2->bf = sp1;

	} // "lee" 파괴

	// bf 가 raw pointer 라면 : 객체 파괴 조사 못함
	// bf 가 weak_ptr 이면    : 객체 파괴 조사 가능
	if ( sp1->bf.expired() )
	{
		std::cout << "객체는 이미 파괴 됨" << std::endl;
	}
}

