#include <iostream>
#include <memory>

int main()
{
	// �Ʒ� �ڵ忡�� �޸��Ҵ�/���� ����� 
	// malloc/free �� �����Ϸ��� �մϴ�.
	// ����� �����ؾ� �ұ�� ? ( ��� ��(4��) ����)
	int* p1 = new int;
	delete p1;

	int* p2 = new int;
	delete p2;

	// STL ���� �޸� �Ҵ���� ������ �ֽ��ϴ�.
	std::allocator<int> ax; // int Ÿ���� �޸𸮸� �Ҵ�/�����ϴ� ��ü
							// C++ ǥ���� �����ϴ� �Ҵ�� 
							// ���������� new/delete ���
	// ���� �޸� �Ҵ� ����� �����Ϸ���
	// => �� ���ٸ� �����ϸ� �˴ϴ�.
	// => �Ʒ� �ڵ�� ����� �ʿ� �����ϴ�.

	int* p3 = ax.allocate(1); // int �Ѱ� �Ҵ�
	ax.deallocate(p3, 1); 

	int* p4 = ax.allocate(1); 
	ax.deallocate(p4, 1);

}