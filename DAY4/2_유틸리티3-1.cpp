#include <iostream> // ǥ�� ����� ��Ʈ��
#include <fstream>  // ȭ�� ��Ʈ��
#include <sstream>  // �޸�(��Ʈ��)��Ʈ��
#include <string>

int main()
{
	double d = 3.14;

	// d�� ���� ���ڿ��� �����Ϸ��� �մϴ�.
	// C ��Ÿ��
	char s[8];
//	sprintf(s, "d = %lf", d); // ���ڿ��� 8�ڸ� ������ �����÷ο�!!
//	snprintf(s, 8, "d = %lf", d); // ���ڿ��� 8�ڸ� ������ �߸��ϴ�.
		
	// C++ ��Ÿ�� 
	// => �پ��� ������ ��ü(����)���� �Ѱ��� ���ڿ��� �����ϴ°�
	std::ostringstream oss;
	oss << "d = " << d;    // cout ó�� ����ϼ���		
							// �ʿ��� ��ŭ �޸𸮰� �Ҵ�ǰ� �˴ϴ�.
							// oss �� ���� "string" �� �ڵ� ����
	oss << "���ڿ� = , " << 20;

	std::string s1 = oss.str();

	std::cout << s1 << std::endl;

	// string ��ü�� "<<" ������ �ȵ˴ϴ�.
//	std::string ss = 

}
