#include <iostream>

// 2. ����Ʈ�����ʹ� ���� ���� ������ �ذ��ؾ� �մϴ�.
// ���� ���� : ����Ʈ ������ ���鶧�� ��� ����.
// ���� ��� : ����Ʈ ������ ���鶧 ���� �θ� ���
// ���� ���� : ����Ʈ ������ ���鶧 ���� �θ� ���

template<typename T>
class Ptr
{
	T*   obj;
	int* ref;  // ��������� ������ ����Ű�� ������
public:
	Ptr(T* p = 0) : obj(p) 
	{
		ref = new int;
		*ref = 1;
	}



	T* operator->() { return obj; }
	T& operator*() { return *obj; }
	~Ptr() { delete obj; }
};



int main()
{
	Ptr<int> p1 = new int;
	Ptr<int> p2 = p1; 
}


