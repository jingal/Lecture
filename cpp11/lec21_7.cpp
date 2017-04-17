#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>
#include <memory>
#include <functional>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	21�� reference wrapper ���� #3
///////////////////////////////////////////////////////////////////////////

//C++ ǥ�� reference_wrapper
template<typename T> struct xreference_wrapper
{
	T* obj;
	xreference_wrapper(T& p) : obj(&p) {}

	operator T&() { return *obj; }
};


int main()
{
	int n = 10;

	xreference_wrapper<int> r1 = n;		//���������δ� �ּҸ� ����..
	//int& r1 = n;
	//�����Ͱ� ������ ����ȯ�� �ʿ��ϴ�.

	int& r2 = r1;	//r1.operator int&()
	r2 = 20;

	cout << n << endl;
}