#include "show.h"
#include <memory>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " �ı�" << std::endl; }

//	std::shared_ptr<People> bf; // ��������� ����

	People* bf; // raw pointer �� ��ü�� ����ų�� �ִ�.
				// ������, ��������� �������� �ʴ´�.
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
// raw pointer ���� �Ʒ��� �������� �ֽ��ϴ�.
int main()
{
	std::shared_ptr<People> sp1(new People("kim"));

	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2.get();
		sp2->bf = sp1.get();
	
	}// <= �̼��� "lee" ��ü�� �ı��˴ϴ�.
	 // <= �׷���, "lee" �� ����Ű�� sp1->bf �� ��� �޸� �ּҸ� ������ 
	 //    �ֽ��ϴ�.

	// �Ʒ� ó�� �����ϸ� "0" �� �ƴ����� �̹� �ı��ǰ� ���� �޸� �ּ��Դϴ�.
	// => "Dangling pointer" ��� �մϴ�.
	if (sp1->bf != 0)
	{
		auto s = sp1->bf->name;
	}
}

