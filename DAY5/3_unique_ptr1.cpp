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

	// ���� �����ڿ� ���Կ����ڸ�
	// �����Ϸ��� ������ ���ϰ� �մϴ�
	Ptr(const Ptr& p) = delete;
	Ptr& operator=(const Ptr&) = delete;

	// ������ C++11�� move�� ���� �մϴ�.
	Ptr(Ptr&& p) : obj(p.obj)
	{
		p.obj = nullptr;
	}
	// move ���Ե�.. �����ϼ���..
};

int main()
{
	Ptr<int> p1 = new int;
	*p1 = 100;
	std::cout << *p1 << std::endl;

//	Ptr<int> p2 = p1; // ���� �����ڰ� ���� �Ǿ����Ƿ� ������ ����.
}


