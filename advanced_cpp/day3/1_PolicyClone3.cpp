// 1_PolicyClone3 - 183 page

#include <iostream>
#include <vector>
using namespace std;


template<typename T, typename Ax = allocator<T>> class vector
{
	T* buff;
	Ax ax; //�޸� �Ҵ��. allocator
public:
	void resize(int sz)
	{
		// �޸� ���Ҵ��� �ʿ��մϴ�.
		// ��� �Ҵ� �ұ��?
		T* P = ax.allocate(sz);

		ax.deallocate(p);
	}
};

int main()
{

}


