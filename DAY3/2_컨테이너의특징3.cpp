#include <vector>
#include "show.h"

template<typename T> class MyAlloc
{
public:
	// 모든 사용자 정의 allocator 는 "allocate/deallocate" 라는 이름의 
	// 함수가 있어야 합니다.(인자도 반환 타입도 전부 약속되어 있습니다.)

	T* allocate(std::size_t sz) // std::size_t : unsigned int
	{
		void* p = malloc(sizeof(T) * sz);
		
		printf("allocate - %d 개 할당, %p\n", sz, p);

		return static_cast<T*>(p); // <== 캐스팅 추가
	}

	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate - %d 개 해지, %p\n", sz, p);
		free(p);
	}


	// 위 2개 외에 아래 3개도 필요 합니다.(약속되어 있습니다.)
	using value_type = T;
	MyAlloc() {}
	template<typename U> MyAlloc(const MyAlloc<U>&) {} // template 생성자
};


int main()
{
//	std::vector<int> v(3); // C++ 표준 메모리 할당기(std::allocator) 사용
						   // => new/delete 로 메모리 할당/해지

	std::vector<int, MyAlloc<int> > v(3);
							// 메모리 할당이 필요하면
							// MyAlloc 의 약속된 멤버함수를 사용해달라는것

	std::cout << "------------" << std::endl;

	v.resize(10);

	std::cout << "------------" << std::endl;

}