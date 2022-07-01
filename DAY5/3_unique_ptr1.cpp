#include <iostream>

template<typename T>
class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
	~Ptr() { delete obj; }

	// 복사 생성자와 대입연산자를
	// 컴파일러가 만들지 못하게 합니다
	Ptr(const Ptr& p) = delete;
	Ptr& operator=(const Ptr&) = delete;

	// 하지만 C++11의 move는 지원 합니다.
	Ptr(Ptr&& p) : obj(p.obj)
	{
		p.obj = nullptr;
	}
	// move 대입도.. 제공하세요..
};

int main()
{
	Ptr<int> p1 = new int;
	*p1 = 100;
	std::cout << *p1 << std::endl;

//	Ptr<int> p2 = p1; // 복사 생성자가 삭제 되었으므로 컴파일 에러.
}


