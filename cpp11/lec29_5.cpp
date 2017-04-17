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
#include <ctime>
#include <algorithm>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	29강 10. 람다 표현식과 auto 인자.
//	29강 11. Nullary 람다
///////////////////////////////////////////////////////////////////////////

int main()
{
	auto f1 = []()	{return 10; };
	auto f2 = []		{return 10; };		//Nullary 람다

}

/*
void foo(auto a) {}		// error

int main()
{
	auto f = [](auto a) {return a; };		//람다표현식은 auto 인자 허용

	cout << f(1) << endl;
	cout << f(1.1) << endl;
}

class Closure
{
public:
	template<typename T> inline T operator()(T a) const 
	{
		return a;
	}
};
*/