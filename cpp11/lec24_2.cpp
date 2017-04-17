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
//	24강 move와 복사를 모두 지원하기 2 - pass by value
///////////////////////////////////////////////////////////////////////////



class Data
{
public:
	Data() {}
	~Data() {}

	Data(const Data& c) { cout << "copy ctor" << endl; }
	Data(Data&& c) noexcept { cout << "move ctor" << endl; }
	Data& operator=(const Data& c) { cout << "copy =" << endl; return *this; }
	Data& operator=(Data&& c) noexcept { cout << "move =" << endl;  return *this; }
};

class Test
{
	Data data;
public:
	//void set(const Data& d) { data = d; }		
	//void set(Data&& d) { data = move(d);}

	void set(Data d) { data = move(d); }
};

int main()
{
	Test t;

	Data d1, d2;	

	t.set(d1);				// copy 1회			copy 1회, move 1회
	t.set(move(d2));		// move 1회			move 1회, move 1회
}
