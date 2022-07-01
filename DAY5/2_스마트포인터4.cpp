#include <iostream>

// C++11�� ����Ʈ�����͸� ����Ϸ��� �ʿ��� ���
#include <memory>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
	// �ٽ� 1. = �ʱ�ȭ�� �Ҽ� ����, () �ʱ�ȭ�� �˴ϴ�.
	// => �����ڰ� explicit ��� �ǹ� �Դϴ�.
	// => explicit �����ڴ� ���� �ʱ�ȭ�� �����մϴ�.
	std::shared_ptr<int> p1(new int);  // ok    ����(direct) �ʱ�ȭ
//	std::shared_ptr<int> p2 = new int; // error ����(copy) �ʱ�ȭ


	// �ٽ� 2. ����Ʈ �������� ũ��
	std::cout << sizeof(p1)   << std::endl; // ��κ� raw pointer�� 
											// 2�� ũ�� ( ������ ���� �ٸ��� ����)

	std::cout << sizeof(int*) << std::endl; // 32bit ȯ�� 4����Ʈ
											// 64bit ȯ�� 8����Ʈ


	// �ٽ� 3. -> �� . ������
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

	// -> ������ : ���ü(Car)�� ����� ���� �ϴ� �� 	
	sp1->Go();

	// . ������ : shared_ptr ��ü�� ����� �����ϴ� ��
	int n = sp1.use_count(); // �������, ��� ����Ʈ�����Ͱ� �ڿ��� ����
							// �ϴ°�?... 2
	std::cout << n << std::endl;
}





