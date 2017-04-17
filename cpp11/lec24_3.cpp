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
//	24�� move�� ���縦 ��� �����ϱ� 3 - Forward Reference (T&&)
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
	//void set(Data d) { data = move(d); }

	template<typename T> void set(T&& d)
	{
		//data = move(d);		// ������ rvalue�� ĳ����..

		//T&& lvalue reference��� lvalue�� ĳ����
		//T&& rvalue reference��� rvalue�� ĳ����
		data = forward<T>(d);
	}
};

int main()
{
	Test t;

	Data d1, d2;

	t.set(d1);						// lvalue => void set (T& d)
	t.set(move(d2));				// rvalue => void set (T&& d)

	//t.set(11);				// ������ ����
}
