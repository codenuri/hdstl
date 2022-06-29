#include <vector>

// resize 의 원리를 생각해 봅시다.
// STL 컨테이너 설계시 "사용자에게 메모리 할당 방식"을 변경할 기회를 주고 싶었습니다.
// 그래서 아래 처럼 설계 되었습니다.(템플릿 2번째 인자가 핵심)
template<typename T, 
		 typename Alloc = std::allocator<T> > 
class vector
{
	T* buff;
	Alloc ax; // 메모리 할당기.
			  // 사용자가 변경하지 않으면 "std::allocator" 사용
			  // 이제 vector 의 모든 멤버 함수 에서는 메모리 할당/해지
			  // 가 필요 할때 마다 ax가 가진 약속된 함수를 사용합니다.
public:
	void resize(int sz)
	{
		// 메모리 할당이 필요한 경우 어떻게 할까요 ?
		// new ? malloc ? memory pool
		buff = ax.allocate(sz); // T 타입을 sz 갯수 할당
		
		ax.deallcate(buff, sz); // 메모리 해지
	}
};

int main()
{
	std::vector<int> v(5);
	v.resize(10);
}


