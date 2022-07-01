#include <iostream>
#include <memory>

void foo(void* p) { free(p); }

int main()
{
	// 삭제자 변경
	std::shared_ptr<int>  sp1(new int); // ok. sp1소멸자가 delete 수행

	// 메모리 할당방법을 변경한 경우
//	std::shared_ptr<int>  sp2((int*)malloc(20)); // 이렇게 하면 안됩니다. 

	std::shared_ptr<int>  sp2((int*)malloc(20), foo);	// 생성자2번째 인자로 
														// 삭제자 함수 전달
														// 단항 함수로 전달해야 합니다
	std::shared_ptr<int>  sp3((int*)malloc(20), free );

	std::shared_ptr<int>  sp4((int*)malloc(20), [](int* p) { free(p); });

	// std::make_shared 사용시는 "객체의 생성을 사용자가 아닌"
	// "make_shared 내부에서 하게 됩니다. 삭제자를 변경할 필요 없습니다."
	std::shared_ptr<int> sp5 = std::make_shared<int>(0);
}







