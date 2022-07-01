#include <iostream>
#include <memory>

class Car
{
public:
	void Go() {}
	~Car() {std::cout << "~Car" << std::endl;	}
};
int main()
{

	std::shared_ptr<Car> p(new Car);
	
//	std::shared_ptr<Car> sp = p; // ������� 2�� ����
	std::weak_ptr<Car>   wp = p; // ������� ���� ����. ��� 1

	std::cout << p.use_count() << std::endl; // 

	if (!wp.expired())
	{
		// ��ü�� �ı����� �ʾ����Ƿ� wp �� ����ؼ� ��ü�� �����ϰ� �ʹ�.
		wp->Go(); // error. wp�δ� ��ü ���� �ȵ�
	}

}

