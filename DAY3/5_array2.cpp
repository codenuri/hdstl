#include "show.h"

// �Ʒ� �ڵ� �߻����� ������
template<typename T, int N>
struct array
{
	T buff[N];

	int size() const { return N; }
	bool empty() const { return N == 0; }

	// STL �����̳ʰ� ������ �ϴ� ��Ģ�� ���Ѿ� �մϴ�
	using value_type = ? ;
	using iterator = ? ;

	iterator begin() { return ? ; }
	iterator end()   { return ? ; }
};

int main()
{
	array<int, 5> arr = { 1,2,3,4,5 }; // �̷��� �ʱ�ȭ�� �����մϴ�
								    // �������� �̹Ƿ� ��� ���(�迭)�� stack��

	// �ᱹ array �� "��¥ �迭"�� ������ �����Դϴ�.
	// �׷���, �迭�� ���� ��� �Լ��� �ֽ��ϴ�.
	std::cout << arr.size() << std::endl;
}