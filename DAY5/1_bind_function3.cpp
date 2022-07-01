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


void foo(void* p)        { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }


int main()
{
	// IOS �� cocoa ���̺귯���� "�뺸����" ��� ������ �ֽ��ϴ�.
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", &goo);

	// ���͸� ����ʿ��� ���͸��� ����������
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}




