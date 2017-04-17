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
//	29강 12. Lambda expression과 conversion
///////////////////////////////////////////////////////////////////////////

int main()
{
	int(*f)(int, int) = [](int a, int b) { return a + b; };
						//class Closure{}; Closure();

	// 지역변수를 캡쳐하면 함수포인터로의 암시적 형변환을 허용하지 않는다.
	int(*f)(int, int) = [=](int a, int b) { return a + b; };
	//class Closure{}; Closure();


	/*
	class Closure
	{
		int v;

	public:
		Closure(int a) : v(a) {}

		// static inline int operator()(int a, int b) // 괄호연산자는 static이 안됨
		inline int operator()(int a, int b) 
		{
			return v+ a + b;
		}

		static inline int dummy(int a, int b)
		{
			return v + a + b;
		}

		typedef int(*PF)(int, int);
		operator PF() { return &Closure::dummy; }
	};
	*/
}