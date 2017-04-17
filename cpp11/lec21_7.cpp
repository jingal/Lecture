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
//	21강 reference wrapper 개념 #3
///////////////////////////////////////////////////////////////////////////

//C++ 표준 reference_wrapper
template<typename T> struct xreference_wrapper
{
	T* obj;
	xreference_wrapper(T& p) : obj(&p) {}

	operator T&() { return *obj; }
};


int main()
{
	int n = 10;

	xreference_wrapper<int> r1 = n;		//내부적으로는 주소를 보관..
	//int& r1 = n;
	//포인터가 참조로 형변환이 필요하다.

	int& r2 = r1;	//r1.operator int&()
	r2 = 20;

	cout << n << endl;
}