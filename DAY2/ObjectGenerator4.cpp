template<typename T>
class list
{
public:
	list() {}
	list(int sz) {}
	list(int sz, T value) {}
};

// class template type deduction guide ��� �����Դϴ�. => C++17
// �����ڸ�� -> list<Ÿ��>
list(int sz)->list<int>;

int main()
{
	list s1(10, 3); // ok.. ������ ���ڷ� T Ÿ�� �߷� ����, C++17����
	list s2(10);    // 
}