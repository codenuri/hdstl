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
	sprintf(s, "d = %lf", d); // ���ڿ��� 8�ڸ� ������ �����÷ο�!!
	snprintf(s, 8, "d = %lf", d); // ���ڿ��� 8�ڸ� ������ �߸��ϴ�.
		
	// C++ ��Ÿ�� 
	std::ostringstream oss;
	oss << "d = " << d;    // cout ó�� ����ϼ���

	std::string s1 = oss.str();

	std::cout << s1 << std::endl;

}
