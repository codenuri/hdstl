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
		for (auto f : notif_map[key]) // notif_map[key] �� �ᱹ vector�Դϴ�.
		{
			f(hint); // f �� function �̹Ƿ� ()�� ȣ��
		}
	}
};

// 64 ��Ʈ ȯ�濡�� void* �� 64��Ʈ �̹Ƿ� int (32��Ʈ)�� ������ ���ٰ� ���.
// => int(32bit) ��� long long(64��Ʈ����)
void foo(void* p)        { std::cout << "foo : " << (long long)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (long long)p << std::endl; }


int main()
{
	// IOS �� cocoa ���̺귯���� "�뺸����" ��� ������ �ֽ��ϴ�.
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY",      std::bind(&goo, _1, 1));
	nc.addObserver("DISCONNECT_WIFI", std::bind(&goo, _1, 2)); 


	// ���͸� ����ʿ��� ���͸��� ����������
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}



