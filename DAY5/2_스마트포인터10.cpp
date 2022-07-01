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
	
//	std::shared_ptr<Car> sp = p; // 참조계수 2로 증가
	std::weak_ptr<Car>   wp = p; // 참조계수 증가 안함. 계속 1

	std::cout << p.use_count() << std::endl; // 

	if (!wp.expired())
	{
		// 객체가 파괴되지 않았으므로 wp 를 사용해서 객체에 접근하고 싶다.
		wp->Go(); // error. wp로는 객체 접근 안됨
	}

}

