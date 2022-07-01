#include <iostream>
#include <functional> // std::function, std::bind �� ���� ���.
using namespace std::placeholders; // _1, _2, 

void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

class Dialog
{
public:
	void Init(int a, int b)
	{
		printf("Dialog Init : %d, %d\n", a, b);
	}
};

int main()
{
	// C ����� �Լ� �����ʹ� �������� �����մϴ�.
//  void(*f)(int) = &f1; // ok

//	f = &f2; // error. f�� ���� �Ѱ�¥�� �Լ� �ּҸ� �����ѵ�, f2�� ���ڰ�2��

	// C++11 ���� ���Ե� std::function �� "�Լ�������"�� �䳻��
	// Ŭ���� ���ø� �Դϴ�.
	// std::function<�Լ�Ÿ��>
	// void(int)    : �Լ� Ÿ��
	// void(*)(int) : �Լ� ������ Ÿ��
	std::function<void(int)> f;
	
	f = &f1;  // & ��� �˴ϴ�.

	f(10); // f1(10);

	// f ���� f2, f3, f4���� �Լ� �ּҵ� ������ �ֽ��ϴ�.
	// => std::bind()�� ���ڸ� ������ ����� ������ �Լ��� ������ �ִٴ°�

//	f = &f2; // error
	f = std::bind(&f2, _1, 3); // ok

	f(10); // f2(10,3) �� �ǹ�

	//=====================
	f = std::bind(&f3, 2, _1, 1 );

	f(10); // f3(2, 10, 1) �� �ǹ̰� �ǵ��� ����� ������

	// f ���� ��� �Լ��� �ּҵ� ������ �ֽ��ϴ�.
	// => ��� �Լ��� ȣ���Ϸ��� ��ü�� �ʿ� �մϴ�
	Dialog dlg;
	f = std::bind(&Dialog::Init, &dlg, _1, 3);

	f(10); // dlg.Init(10, 3) �� �ǹ�

	// ���. "std::function<void(int)>" �� f ����
	// => ���ڰ� int �Ѱ� �̻� �ִ� ��� ������ �Լ�(�Լ���ü)��
	// => �� �����Ҽ� �ֽ��ϴ�.(std::bind ����ؼ�)
}












