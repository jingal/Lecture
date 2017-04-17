#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>
#include <memory>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	21강 Perfect forwarding 주의사항
///////////////////////////////////////////////////////////////////////////

template<typename F, typename ... Types>
decltype(auto) logTime(F&& f, Types&& ... args)
{
	return f(forward<Types>(args)...);
}


// 0은 int에서 특별하게 처리하기 때문에 포인터가 되지만, 임의의 타입의 인티저는 포인터로 변환 안됨
void foo(int* p) {}

int main()
{
	//foo(0);

	//logTime(foo, 0);

	logTime(foo, nullptr); //perfect forwarding에서 *0을 보내고 싶을경우, nullptr 을 사용해야 함.
}
