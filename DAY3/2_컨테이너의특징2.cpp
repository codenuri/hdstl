#include <vector>

// resize �� ������ ������ ���ô�.
// STL �����̳� ����� "����ڿ��� �޸� �Ҵ� ���"�� ������ ��ȸ�� �ְ� �;����ϴ�.
// �׷��� �Ʒ� ó�� ���� �Ǿ����ϴ�.(���ø� 2��° ���ڰ� �ٽ�)
template<typename T, 
		 typename Alloc = std::allocator<T> > 
class vector
{
	T* buff;
	Alloc ax; // �޸� �Ҵ��.
			  // ����ڰ� �������� ������ "std::allocator" ���
			  // ���� vector �� ��� ��� �Լ� ������ �޸� �Ҵ�/����
			  // �� �ʿ� �Ҷ� ���� ax�� ���� ��ӵ� �Լ��� ����մϴ�.
public:
	void resize(int sz)
	{
		// �޸� �Ҵ��� �ʿ��� ��� ��� �ұ�� ?
		// new ? malloc ? memory pool
		buff = ax.allocate(sz); // T Ÿ���� sz ���� �Ҵ�
		
		ax.deallcate(buff, sz); // �޸� ����
	}
};

int main()
{
	std::vector<int> v(5);
	v.resize(10);
}


