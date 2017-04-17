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
//	25강 value categories
///////////////////////////////////////////////////////////////////////////

class Object
{

};

// lvalue : has id, no move
// xvalue : has id, move
// prvalue : no id, move - C++98/03 시절의 rvalue

int main()
{
	Object o1;									// lvalue, has id
	Object o2 = o1;								// copy
	Object o3 = Object();						// rvalue, no id, move, 10
	Object o4 = static_cast<Object&&>(o1);		// has id, move,
}
