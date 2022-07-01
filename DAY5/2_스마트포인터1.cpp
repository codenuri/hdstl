// 134page ~
#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};

// �Ʒ� Ptr �� �ٽ��Դϴ�.
// ���� : ���� Ÿ���� ��ü�� "�ٸ� Ÿ���� ������ ��Ȱ"�� �ϴ� ��
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }
};

int main()
{
	// "Ptr" Ÿ���� "��ü" p��
	// "Car" Ÿ���� "������" ó�� ���˴ϴ�.
	Ptr p = new Car; // Ptr p( new Car ) �� �����ϼ���. 

	p->Go(); // ( p.operator->())Go() �� ����ε�
			 // ( p.operator->())->Go() ó�� �ؼ��˴ϴ�.

	(*p).Go(); // ( p.operator*() ).Go() �Դϴ�.
}


