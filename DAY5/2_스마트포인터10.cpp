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
		// wp->Go(); // error. wp로는 객체 접근 안됨
					 // -> 연산자가 재정의 되어 있지 않음.
					// 이유 : wp 로 멤버 함수 사용중에 "p"가 파괴되면
					//		객체가 파괴되므로 문제가 발생..

		// 방법 : 객체의 참조 계수를 증가하고 접근해야 한다.
		//       객체의 참조 계수를 증가하는 방법은 "shared_ptr"을 한개 더
		//		 만들어야 한다.

		std::shared_ptr<Car> sp2 = wp.lock();

		if (sp2)
			sp2->Go();
	}

}

