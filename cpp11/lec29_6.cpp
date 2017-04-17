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
//	29�� 12. Lambda expression�� conversion
///////////////////////////////////////////////////////////////////////////

int main()
{
	int(*f)(int, int) = [](int a, int b) { return a + b; };
						//class Closure{}; Closure();

	// ���������� ĸ���ϸ� �Լ������ͷ��� �Ͻ��� ����ȯ�� ������� �ʴ´�.
	int(*f)(int, int) = [=](int a, int b) { return a + b; };
	//class Closure{}; Closure();


	/*
	class Closure
	{
		int v;

	public:
		Closure(int a) : v(a) {}

		// static inline int operator()(int a, int b) // ��ȣ�����ڴ� static�� �ȵ�
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