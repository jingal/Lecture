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
//	24�� move�� ���縦 ��� �����ϱ� 1 - �Լ� �����ε�
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
		data = d;	// ���� ���Կ�����.
	}

	//1. �Լ������ε�
	void set(Data&& d)
	{
		data = move(d);	// ���� ���Կ�����.
	}

	// ������ ����/���� �� �� ����.
	// ������ �Լ��� �ΰ��� ��������.
};

int main()
{
	Test t;

	Data d1;
	Data d2;

	t.set(d1);			//d1�� ����ȴ�. ��� ��밡��..
	t.set(move(d2));	//move�� �ϰ�ʹ�. d2�� ��� ����� �� ����.

	//vector<int> v;
	//v.push_back();
}
