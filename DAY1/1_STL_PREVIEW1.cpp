// 1_STL_PREVIEW1
#include <iostream>
#include <string>

int main()
{
	char s1[] = "Hello";
	char s2[] = "Hello";

	if (s1 == s2) {} // ���ڿ� �񱳰� �ƴ� �迭 �ּ� ��, �׻� false
					 // "strcmp(s1, s2) == 0"
	
	s2 = s1; // error. 
		     // strcpy(s2, s1) �Ǵ� strcpy_s(s2, strlen(s1)+1, s1)

	// C++ ǥ�ؿ��� "std::string" Ÿ�� ����
	std::string s3 = "hello";
	std::string s4 = s3;

	if (s3 == s4) {} // �񱳵� ����

	s4 = s3 + s3; // ������ ����
//	s4 = s3 * 3;  // ������ �ȵ�

}








// Visual studio  ����Ͻô� �е���

// 1. ������Ʈ ����� ���� �ּ���

// 2. "������Ʈ �޴�" => "DAY1 �Ӽ��޴�"
//    => �÷��� ��������
//    => Windows SDK ���� ������ �ּ���

