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
//	29강 7. 람다 표현식과 지역 변수 캡쳐
///////////////////////////////////////////////////////////////////////////

int main()
{
	int v1 = 0;
	int v2 = 0;


	//auto f1 = [](int a) {return a + v1; };		//error

	//auto f1 = [v1](int a) {return a + v1; };			//ok
	//auto f2 = [v1, v2](int a) {return a + v1; };		//ok

	// 일반 람다 : ()연산자 함수가 상수가 된다.
	//auto f3 = [=](int a) {return a + v1; };				// 모든 지역 변수 캡쳐


	// mutable 람다 : () 연산자 함수가 비상수 함수가 된다.
	auto f4 = [=](int a) mutable {v1 = 10;  return a + v1 + v2; };				// error. v1은 read만 가능..

	f4(10);		//v1 = 10이 실행된다.... 멤버 data v1이 변경된다.

	cout << v1 << endl;		//0

	/*
	class Closure
	{
		int v1;
		int v2;

	public:
		Closure(int a, int b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			// 상수 함수이기 때문에 멤버변수를 변경할 수 없음
			v1 = 10;
			return a + v1 + v2;
		}
	};

	//지역 변수를 클로져 객체에 전달
	auto f1 = Closure(v1, v2);
	*/
}


/*
// 전역변수

int g = 0;

int main()
{
	auto f1 = [](int a) {g = 10; return g + a; };	//ok.. 전역변수는 언제라도 접근가능. R/W 모두 가능. 

	cout << f1(5) << endl;

	cout << g << endl;
}
*/