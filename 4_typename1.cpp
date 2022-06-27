class Test
{
public:
	enum { value = 1 };
	typedef int DWORD;
};
int p = 0;

template<typename T> void foo(T a)
{
	// �Ʒ� 2�ٿ��� * �� �ǹ̸� ������ ������(1. ���ϱ�, 2. ������ ���� ����)
	
	// Ŭ�����̸�::"�̸�" ���� "�̸�"�� �ǹ�
	// 1. ��   �ϼ� �ִ�. : enum ���, static ��� ����Ÿ��.
	// 2. Ÿ�� �ϼ� �ִ�. : typedef �Ǵ� using ��.. 
	
//	Test::value * p; // ���ϱ��� �ǹ�
//	Test::DWORD * p; // ������ ���� p�� �����ϴ� �ڵ�

	// dependent name : ���ø� ���� T �� ������ �̸�
	//					�����Ϸ��� �⺻ ������ "��"���� �ؼ�
	T::value * p; // ok
//	T::DWORD * p; // error
	typename T::DWORD* p;	// ok.. depedent name �� 
							// Ÿ���� �̸��̶�� �˷��ִ� ��
}


int main()
{
	Test t;
	foo(t);
}