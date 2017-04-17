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
//	29강 9. 변수 캡쳐 주의 사항
///////////////////////////////////////////////////////////////////////////

function<void(int)> f;

class Test
{
	int data;
public:
	void foo()
	{
		f = [this](int a) {data = a; };
	}
};

int main()
{
	Test* p = new Test;
	p->foo();
	delete p;		//객체파괴

	f(5);			// this->data = 5;
}

/*
주의 1번

int main()
{
	function<void(int)> f;

	{
		int v = 10;			//f실행 시점에 v는 파괴됨
		f = [&v](int a) {v = a; };
	}

	f(5);
}
*/