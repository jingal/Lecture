#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
//#include <vector>
#include <boost/type_index.hpp>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	19강 6.Reference collapse
///////////////////////////////////////////////////////////////////////////


//compile 타임에 타입 추론 : typedef(using), template, auto, decltype

template<typename T> void foo()
{
	cout << type_id_with_cvr<T&>().pretty_name() << endl;
	cout << type_id_with_cvr<T&&>().pretty_name() << endl;
}

int main()
{
	foo<int&>();		//T& : int& &  => int &
	foo<int&&>();		//T&& : int&& && => int &&

	int n = 10;
	int& r = n;
	//int& & rr = r;
}
