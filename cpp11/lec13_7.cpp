#include <iostream>
#include <type_traits>
//#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	initializer_list
///////////////////////////////////////////////////////////////////////////

template<typename T> class vector
{
	T *buff;

public:
	vecotr(size_t sz, T initValue = T()) {}		//1
	vector(initializer_list<T> s) {}			//2
};


int main()
{
	vector<int> v1(10, 3);			//1��, 10���� 3���� �ʱ�ȭ
	vector<int> v2{ 10, 3 };		//2���� ���, 10, 3

	vector<int> v3{ 1,2,3,4,5,6,7,8,9,10 };
}
	
