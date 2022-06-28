// ObjectGenerator1.cpp
template<typename T>
T square(T a)
{
	return a * a;
}

template<typename T> class list
{
public:
	list(int sz, T value) {}
};

// C++14������ Ŭ���� ���ø��� �׻� Ÿ�����ڸ� �����ؾ� �մϴ�.
// �� ��� �� ������ ���ϼ� �ֽ��ϴ�.
// �Լ� ���ø��� ������ ������ ���մϴ�.
// => object generator ��� �Ҹ��� ��� �Դϴ�.
// => ����! make_list �� ǥ�ؿ��� �����ϴ�.
template<typename T> 
list<T> make_list(int sz, T value)
{
	return list<T>(sz, value);
}

int main()
{
	// ������ ���� ���̴� ���� ?
	square<int>(3);	// �Լ� ���ø��� ����ϴ� ��Ȯ�� ǥ���
	square(3);		// Ÿ�� ���� ������, �����Ϸ��� �Լ� ���ڸ� ����
					// T�� Ÿ�� �߷�

	// Ŭ���� ���ø��� Ÿ�� �߷�
	list<int> s1(10, 3);
	list      s2(10, 3); // ������ ���ڸ� ���� Ÿ�� �߷� ?
						 // C++17 ���� ������ ����
						 // C++14 ������ �ȵ˴ϴ�.

	auto s3 = make_list<int>(10, 3); // Ÿ���� ������ ��Ȯ�� ǥ���
	auto s4 = make_list(10, 3); // ������, �Լ� ���ø��� Ÿ������ ������ �����մϴ�.

}
// type deduction�� parameter�� �ִ� ��츸 �����ϰڳ׿�? => �� �ȵ˴ϴ�