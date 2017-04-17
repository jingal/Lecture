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
//	24강 std::move 만들기
///////////////////////////////////////////////////////////////////////////


class Test
{	
public:
	Test() = default;
	Test(const Test&) { cout << "copy" << endl; }
	Test(Test&&) { cout << "move" << endl; }
};

template<typename T> typename remove_reference<T>::type&& xmove(T&& a)
{
	return static_cast<typename remove_reference<T>::type &&>(a);
}
 
int main()
{
	Test t1;
	Test t2 = t1; 
	Test t3 = static_cast<Test&&>(t1);
	Test t4 = xmove(t1);					//copy
											// t1 : lvalue		T : Test &	T&& : Test& && => Test&
											// static_cast<Test&>(a)
	Test t5 = xmove(Test());
}
