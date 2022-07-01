#include <memory>
#include <iostream>
// shared_ptr의 경우에도 함수객체 전달이 가능한거죠? 
// => 네, 생성자 2번째 인자로 보내면 됩니다.
// 
// 그리고 Freer의 operator()이 inline이 아닌 것에는 이유가 있을까요?
// => inline 표기 안해도, 멤버 함수를 선언 안에 구현하면 자동으로 inline됩니다.

struct Freer
{
	inline void operator()(void* p)
	{
		free(p);
	}
};
// 삭제자를 template 인자로 받으면 보관장소가 없어도 됩니다.
template<typename T, typename Dx>
class unique_ptr
{
	T* obj;
public:
	~unique_ptr()
	{
		Dx d; // 삭제자 객체를 생성해서
		d(obj); // 삭제.. 
				// 삭제자를 별도로 보관하지 않고 있습니다.
	}
};


int main()
{
	// 삭제자 변경
	// shared_ptr : 생성자의 2번째 인자로 전달
	// unique_ptr : 템플릿 2번째 인자로 함수 객체 전달
	std::shared_ptr<int>        sp1(static_cast<int*>(malloc(sizeof(int)), free);
	std::unique_ptr<int, Freer> up1(static_cast<int*>(malloc(sizeof(int)));

	std::shared_ptr<int> sp2(new int);
	std::unique_ptr<int> up2(new int);


	// shared_ptr vs unique_ptr
	// shared_ptr은 삭제자를 변경해도 같은 타입 입니다. => 동일 컨테이너에 보관도 가능
	// unique_ptr은 삭제자를 변경하면 다른 타입 입니다. 

	// shared_ptr 은 관리 객체에 삭제자를 보관했다가 사용합니다.




	// new 의 배열로 할당하는 경우

	std::unique_ptr<int> up1(new int);     // ok 소멸자가 delete
//	std::unique_ptr<int> up2(new int[10]); // 버그.. 
	std::unique_ptr<int[]> up2(new int[10]); // ok.. C++14 부터 지원
								// C++14 이전에는 템플릿 인자로 삭제자를 전달

	std::shared_ptr<int[]> sp(new int[10]); // C++17부터 지원

	// 단, new int[10] 같은게 필요하면 "스마트포인터 보다"
	// vector를 먼저 고려해 보세요
	// std::vector<int> v(10);
}