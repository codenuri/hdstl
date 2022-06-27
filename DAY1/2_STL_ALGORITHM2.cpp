#include <iostream>

// Step 2. �˻� ������ �Ϲ�ȭ

// => ��ü ���ڿ� �� �ƴ϶� "�κ� ���ڿ�"�� �˻� ���� 
// => Ȱ�뵵�� �о����� => "�Ϲ�ȭ(generic)" �̶�� ǥ��

// [first, last) ������ ���ڿ����� ���� �˻� ����
// => �� ���� ����(half-open range)
char* strchr(char* first, char* last, int c)
{
	while (first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}



int main()
{
	char s[] = "abcdefgh";

	char* p = strchr(s, s+4, 'c');

	if (p == 0)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}