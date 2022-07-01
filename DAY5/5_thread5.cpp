// www.godbolt.org 에 접속해 보세요..
// "언어 선택 콤보박스" C++로 맞추고
// 아래 코드 붙여 넣으세요
#include <atomic>

int a = 0;
int b = 0;

// A 스레드 실행
void foo()
{
	a = b + 1;

	// 메모리 펜스를 설치 합니다.
	// 펜스위의 코드는 펜스 아래로 내려갈수 없습니다
//	__asm { mfence }   // 인텔 CPU의 명령입니다. 
						// ARM 등 다른 CPU 에서는 다른 명령 사용해야 합니다.
	std::atomic_thread_fence(std::memory_order_seq_cst); 
						// 이렇게 하면 컴파일러가 각 CPU 에 맞도록
						// 기계어 코드 생성해 줍니다.
	b = 1;
}

// B 스레드 실행
void goo()
{
	if (b == 1)
	{
		// a는 반드시 1일까요 ??????
		// 
	}
}

int main()
{
}