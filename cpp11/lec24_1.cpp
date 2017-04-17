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
//	24강 move와 복사를 모두 지원하기 1 - 함수 오버로딩
///////////////////////////////////////////////////////////////////////////



class Data
{	
public :
	Data() {}
	~Data() {}

	Data(const Data& c) { cout << "copy ctor" << endl; }
	Data(Data&& c) noexcept { cout << "move ctor" << endl; }
	Data& operator=(const Data& c) { cout << "copy =" << endl; return *this;}
	Data& operator=(Data&& c) noexcept { cout << "move =" << endl;  return *this;}
};

class Test
{
	Data data;
public:
	void set(const Data& d)
	{
		data = d;	// 복사 대입연산자.
	}

	//1. 함수오버로딩
	void set(Data&& d)
	{
		data = move(d);	// 복사 대입연산자.
	}

	// 장점은 복사/무브 둘 다 가능.
	// 단점은 함수를 두개씩 만들어야함.
};

int main()
{
	Test t;

	Data d1;
	Data d2;

	t.set(d1);			//d1은 복사된다. 계속 사용가능..
	t.set(move(d2));	//move로 하고싶다. d2는 계속 사용할 수 없다.

	//vector<int> v;
	//v.push_back();
}
