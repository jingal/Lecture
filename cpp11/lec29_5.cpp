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
//	29�� 10. ���� ǥ���İ� auto ����.
//	29�� 11. Nullary ����
///////////////////////////////////////////////////////////////////////////

int main()
{
	auto f1 = []()	{return 10; };
	auto f2 = []		{return 10; };		//Nullary ����

}

/*
void foo(auto a) {}		// error

int main()
{
	auto f = [](auto a) {return a; };		//����ǥ������ auto ���� ���

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