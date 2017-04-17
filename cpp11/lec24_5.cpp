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
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	24�� move() vs forward()
///////////////////////////////////////////////////////////////////////////

template<typename T> void foo(T&& arg)
{
	//cout << type_id_with_cvr<T&&>().pretty_name() << endl;

	// move : arg�� ������ rvalue�� ĳ����
	cout << type_id_with_cvr<decltype(move(arg))>().pretty_name() << endl;

	// forward : arg�� T&&�� ĳ������ �޶�.
	cout << type_id_with_cvr<decltype(forward<T>(arg))>().pretty_name() << endl;
}


int main()
{
	int n = 10;

	foo(n);				//lvalue : T&& => int&		arg : lvalue
	foo(10);			//rvalue : T&& => int&&		arg : lvalue
}
