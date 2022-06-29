#include <vector>
#include "show.h"

template<typename T> class MyAlloc
{
public:
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);

		printf("allocate - %d byte �Ҵ�, %p\n", sz, p);
		return p;
	}
	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate - %d byte ����, %p\n", sz, p);
		free(p);
	}
	// �� 2�� �ܿ� �Ʒ� 3���� �ʿ� �մϴ�.(��ӵǾ� �ֽ��ϴ�.)
	using value_type = T;
	MyAlloc() {}
	template<typename U> MyAlloc(const MyAlloc<U>&) {}
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