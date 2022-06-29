#include <vector>
#include "show.h"

template<typename T> class MyAlloc
{
public:
	// ��� ����� ���� allocator �� "allocate/deallocate" ��� �̸��� 
	// �Լ��� �־�� �մϴ�.(���ڵ� ��ȯ Ÿ�Ե� ���� ��ӵǾ� �ֽ��ϴ�.)

	T* allocate(std::size_t sz) // std::size_t : unsigned int
	{
		void* p = malloc(sizeof(T) * sz);
		
		printf("allocate - %d �� �Ҵ�, %p\n", sz, p);

		return static_cast<T*>(p); // <== ĳ���� �߰�
	}

	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate - %d �� ����, %p\n", sz, p);
		free(p);
	}


	// �� 2�� �ܿ� �Ʒ� 3���� �ʿ� �մϴ�.(��ӵǾ� �ֽ��ϴ�.)
	using value_type = T;
	MyAlloc() {}
	template<typename U> MyAlloc(const MyAlloc<U>&) {} // template ������
};


int main()
{
//	std::vector<int> v(3); // C++ ǥ�� �޸� �Ҵ��(std::allocator) ���
						   // => new/delete �� �޸� �Ҵ�/����

	std::vector<int, MyAlloc<int> > v(3);
							// �޸� �Ҵ��� �ʿ��ϸ�
							// MyAlloc �� ��ӵ� ����Լ��� ����ش޶�°�

	std::cout << "------------" << std::endl;

	v.resize(10);

	std::cout << "------------" << std::endl;

}