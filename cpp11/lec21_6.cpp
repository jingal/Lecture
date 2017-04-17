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

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	21�� reference wrapper ���� #2
///////////////////////////////////////////////////////////////////////////

void foo(int& r) { r = 10;  }



// �����Ͱ� ������ �Ͻ��� ����ȯ�� �ʿ��ϴ�. reference wrapper
//void logTime(F f, T&& arg)		//int& arg
template<typename F, typename T> void logTime(F f, T arg)		// T : int*
{
//	f(std::forward<T>(arg));
	f(arg);
}

int main()
{
	int n = 0;

	function<void()> f = bind(&foo, n);		//n�� ������ �ƴ� ������ �����ϰ� �ȴ�.

	//logTime(foo, n);
	logTime(foo, &n);

	cout << n << endl;
}


/*
int main()
{
	function<void()> f;

	{
		int n = 0;
		logTime(foo, n);		//�߰��� ���纻 ����� �ȵ�, ������ ����
								// �� ����.. �̹� foo�� ����ȴ�.

		f = bind(&foo, n);		// �̼��� foo�� n�� �����Ѵ�. => n�� ������ �����Ѵ�.
								// bind�� ������ �ƴ� ������ ����
	} //n�� �ı��ȴ�.

	f();					// �̼��� foo(n) ����

	cout << n << endl;
}
*/