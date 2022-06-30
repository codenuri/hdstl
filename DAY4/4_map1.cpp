// 6_map1
#include "show.h"

#include <map>  

// map : pair �� �����ϴ� set,   key ������ value �� ����
int main()
{
	// �ٽ� 1. map ��ü �����ϴ� ��
	// => set<Ű��Ÿ��,           �񱳰�ü, �޸� �Ҵ��>
	// => map<Ű��Ÿ��, valueŸ��, �񱳰�ü, �޸� �Ҵ��>

	std::map<std::string, std::string> m;
		// std::pair<std::string, std::string> ����

	// ��� �ֱ�
	// 1. pair ���� �ֱ�
	std::pair<std::string, std::string> p1("mon", "������");
	m.insert(p1);

	// 2. make_pair
	m.insert( std::make_pair("tue", "ȭ����") );


	// 3. C++11 ���ʹ� {}�ε� ���԰���
	// => C++11 �� "brace-init" ���� ������ ����
	m.insert( { "wed", "������" } );
	
	
	// 4. [] ������ ��� - m[Ű��] = value
	m["fri"] = "�ݿ���";


	//------------------------
	
	// �ݺ��ڿ� ���ؼ�
	auto p = m.find("wed"); // find(Ű��)

	// p�� ����ؼ� "wed : ������" �̶�� ����غ�����

	// [] ������
	std::cout << m["sun"] << std::endl; 
}




