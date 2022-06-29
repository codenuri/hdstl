// 5_�Լ���ü10
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // C++98 ���� �����Ǵ� C++ ǥ�� �Լ� ��ü��

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// ����å���� �Լ���ü�� �����ϴ� �ڵ�
	std::sort(v.begin(), v.end(), std::less<int>());

	// �� ��å���� "����ǥ����"�� ����ϴ� �ڵ� - C++11
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );

	// ����ǥ������ ����ϸ� �����Ϸ��� �Ʒ� �ڵ带 �����մϴ�
	// �� ������ �Ʒ� ������ �κа� ������ �����մϴ�
	class CompilerGeneratedName
	{
	public:
		inline bool operator()(int a, int b) const
		{
			return a < b;
		}
	};
	std::sort(v.begin(), v.end(), CompilerGeneratedName() );
	//============================
	// ��� : ���� ǥ������ "�Լ� ��ü"�� �����ϴ� ǥ����Դϴ�.
	// => ���� ǥ������ ���� �����Ϸ��� ���� ���� Ŭ������ �����
	// => ���� ǥ������ ���� �ڸ��� "�ӽð�ü" ���·� �����ϰ� �˴ϴ�
}

// �Ϲ� �Լ�  (��Ȯ���� �ش� �Ϲ� �Լ��� ������)�� ���޵Ǿ ������ �� 
// Ư�� �Ϲ� �Լ��� ������ �ȴٸ� ġȯ �����Ұ� ������, �׷��� ���ϴ� ������ �������?
// sort(x, x+10, cmp1); // �̶� ���� sort �ȿ� cmp1�� ġȯ�ϸ�
// sort(x, x+10, cmp2); // �̶��� ��� �ұ�� ??
