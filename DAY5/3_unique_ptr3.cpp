#include <memory>
#include <iostream>

struct Freer
{
	void operator()(void* p)
	{
		free(p);
	}
};

int main()
{
	// 삭제자 변경
	// shared_ptr : 생성자의 2번째 인자로 전달
	// unique_ptr : 템플릿 2번째 인자로 함수 객체 전달
	std::shared_ptr<int> sp(static_cast<int*>(malloc(sizeof(int)), free);
	std::unique_ptr<int, Freer> up(static_cast<int*>(malloc(sizeof(int)));


	// shared_ptr vs unique_ptr






	std::unique_ptr<int> up1(new int);
	std::unique_ptr<int> up2(new int[10]);
}