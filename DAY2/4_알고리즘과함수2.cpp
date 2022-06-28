#include <iostream>
#include <list>
#include <algorithm>
#include "show.h"

int foo(int a, int b) { return a + b; }

int main()
{
    std::list<int> s1 = { 1,2,3,4,5};
    std::list<int> s2 = { 6,7,8,9,10 };
    std::list<int> s3;

    // transform �˰���
//    std::transform(s1.begin(), s1.end(),   // 1. �̱����� ��ҵ���
//                   s2.begin(),             // 2. �̱����� ��ҿ� �Բ�
//                   //s3.begin(),// 4. �Լ��� ����� ���⿡ ��ƴ޶�
//                   std::back_inserter(s3), 
//                   foo);      // 3. �� �Լ��� ������

    // s1 �� s2 ������ �� ����� "��"�� s3�� �־� ������
    // ��, ���� ǥ�������� �غ�����.. 
    std::transform(s1.begin(), s1.end(), 
                   s2.begin(), 
                   std::back_inserter(s3),
                   [](int a, int b) { return a * b; });

    show(s3);

    std::list<int> s4;

    // transform �� ���� 4���� ������ �ֽ��ϴ�.
    std::transform(s1.begin(), 
                   s1.end(),
                   std::back_inserter(s4),
                   [](int a) { return a * 10; });

    show(s4);
	return 0;
}



















//
