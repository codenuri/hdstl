#include <iostream>

// 18page ~
// Step 1. C ǥ�� �Լ�

char* strchr( char* s, int c)
{
	while (*s != 0 && *s != c)
		++s;
	return *s == 0 ? 0 : s;
}

int main()
{
	char s[] = "abcdefgh";

	char* p = strchr(s, 'c');

	if (p == 0)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}