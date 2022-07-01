#include <iostream>
#include <memory>

void foo(void* p) { free(p); }

int main()
{
	// ������ ����
	std::shared_ptr<int>  sp1(new int); // ok. sp1�Ҹ��ڰ� delete ����

	// �޸� �Ҵ����� ������ ���
//	std::shared_ptr<int>  sp2((int*)malloc(20)); // �̷��� �ϸ� �ȵ˴ϴ�. 

	std::shared_ptr<int>  sp2((int*)malloc(20), foo);	// ������2��° ���ڷ� 
														// ������ �Լ� ����
														// ���� �Լ��� �����ؾ� �մϴ�
	std::shared_ptr<int>  sp3((int*)malloc(20), free );

	std::shared_ptr<int>  sp4((int*)malloc(20), [](int* p) { free(p); });

	// std::make_shared ���ô� "��ü�� ������ ����ڰ� �ƴ�"
	// "make_shared ���ο��� �ϰ� �˴ϴ�. �����ڸ� ������ �ʿ� �����ϴ�."
	std::shared_ptr<int> sp5 = std::make_shared<int>(0);
}







