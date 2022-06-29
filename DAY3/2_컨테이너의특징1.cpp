#include <iostream>
#include <memory>

int main()
{
	// 아래 코드에서 메모리할당/해지 방법을 
	// malloc/free 로 변경하려고 합니다.
	// 몇군데를 변경해야 할까요 ? ( 모든 곳(4줄) 변경)
	int* p1 = new int;
	delete p1;

	int* p2 = new int;
	delete p2;

	// STL 에는 메모리 할당기라는 개념이 있습니다.
	std::allocator<int> ax; // int 타입의 메모리를 할당/해지하는 객체
							// C++ 표준이 제공하는 할당기 
							// 내부적으로 new/delete 사용
	// 이제 메모리 할당 방식을 변경하려면
	// => 위 한줄만 변경하면 됩니다.
	// => 아래 코드는 변경될 필요 없습니다.

	int* p3 = ax.allocate(1); // int 한개 할당
	ax.deallocate(p3, 1); 

	int* p4 = ax.allocate(1); 
	ax.deallocate(p4, 1);

}