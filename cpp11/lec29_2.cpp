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

	//auto f1 = [](int a) { v1 = a;};						//error	
	//Wauto f2 = [v1, v2](int a) {v1 = a; };				//error. 접근가능. 읽기로만 접근, 
															// ()연산자 함수가 상수 함수

	auto f2 = [v1, v2](int a) mutable { v1 = a; };			// ok. 접근 가능. R/W 모두 가능. 복사본 변경
															// ()연산자 함수가 상수 함수가 아님..
	
	//auto f3 = [=](int a) {return a + v1; };				// 모든 지역 변수 캡쳐



	// 참조로 캡쳐 - 클로져 멤버 data가 참조로 ...
	auto f4 = [&v1, &v2](int a) mutable { v1 = a; };		// ok. 원본변경

	f4(20);

	cout << v1 << endl;
	/*
	class Closure
	{
		int &v1;
		int &v2;

	public:
		Closure(int a, int b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			v1 = 10;		
			return a + v1 + v2;
		}
	};

	auto f5 = Closure(v1, v2);
	*/
}
