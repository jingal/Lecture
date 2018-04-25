// 1_PolicyClone3 - 183 page

#include <iostream>
#include <vector>
using namespace std;


template<typename T, typename Ax = allocator<T>> class vector
{
	T* buff;
	Ax ax; //메모리 할당기. allocator
public:
	void resize(int sz)
	{
		// 메모리 재할당이 필요합니다.
		// 어떻게 할당 할까요?
		T* P = ax.allocate(sz);

		ax.deallocate(p);
	}
};

int main()
{

}


