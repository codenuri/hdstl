#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;

	std::map<std::string, std::vector<HANDLER> > notif_map;
public:
	void addObserver(const std::string& key, HANDLER func)
	{
		notif_map[key].push_back(func);
	}
	void postNotificationWithName(const std::string& key, void* hint)
	{
		for (auto f : notif_map[key]) // notif_map[key] 는 결국 vector입니다.
		{
			f(hint); // f 는 function 이므로 ()로 호출
		}
	}
};

// 64 비트 환경에서 void* 가 64비트 이므로 int (32비트)에 담을수 없다고 경고.
// => int(32bit) 대신 long long(64비트정수)
void foo(void* p)        { std::cout << "foo : " << (long long)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (long long)p << std::endl; }


int main()
{
	// IOS 의 cocoa 라이브러리에 "통보센터" 라는 개념이 있습니다.
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY",      std::bind(&goo, _1, 1));
	nc.addObserver("DISCONNECT_WIFI", std::bind(&goo, _1, 2)); 


	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}




