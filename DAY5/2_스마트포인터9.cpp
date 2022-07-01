#include "show.h"
#include <memory>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " �ı�" << std::endl; }

	//	std::shared_ptr<People> bf; // ��������� ����

//	People* bf; // raw pointer �� ��ü�� ����ų�� �ִ�.
				// ������, ��������� �������� �ʴ´�.	
				// �׷���, ����Ű�� ���� ��ü�� �ı��Ǿ����� ���縦 ���մϴ�
				// "Dangling pointer" �� ������ �ֽ��ϴ�.

	std::weak_ptr<People> bf;	// ������� ���� ����
								// ��ü �ı� ���� ����
								// Dangling pointer �߻� �ȵ� 
};
int main()
{
	std::shared_ptr<People> sp1(new People("kim"));

	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2;
		sp2->bf = sp1;

	} // "lee" �ı�

	// bf �� raw pointer ��� : ��ü �ı� ���� ����
	// bf �� weak_ptr �̸�    : ��ü �ı� ���� ����
	if ( sp1->bf.expired() )
	{
		std::cout << "��ü�� �̹� �ı� ��" << std::endl;
	}
}

