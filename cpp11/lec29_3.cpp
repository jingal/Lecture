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
//	29�� 8. ���� ǥ���İ� ��� ������ ĸ��
///////////////////////////////////////////////////////////////////////////

class Test
{
	int data;
public:
	Test() : data(10) {}

	void foo()	// void foo( Test* const this)
	{
		//auto f = []() { return data; };			// error
		//auto f = [data]() { return data; };		// error
		//auto f = [this]() { return data; };		// ok..

		auto f = [this]() { data = 0; return data; };	//��ü�� �ּҸ� ���纻�� ����
														// data �� ���� ��, ���� ����� ����.
		cout << f() << endl;
	}
};

int main()
{
	int v1 = 0;
	int v2 = 0;

	//auto f1 = [](int a) { v1 = a;};						//error	
	//Wauto f2 = [v1, v2](int a) {v1 = a; };				//error. ���ٰ���. �б�θ� ����, 
	// ()������ �Լ��� ��� �Լ�

	auto f2 = [v1, v2](int a) mutable { v1 = a; };			// ok. ���� ����. R/W ��� ����. ���纻 ����
															// ()������ �Լ��� ��� �Լ��� �ƴ�..

															//auto f3 = [=](int a) {return a + v1; };				// ��� ���� ���� ĸ��



															// ������ ĸ�� - Ŭ���� ��� data�� ������ ...
	auto f4 = [&v1, &v2](int a) mutable { v1 = a; };		// ok. ��������

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

	auto a1 = [v1, &v2]() {};
	auto a2 = [v1, &]() {};
	auto a3 = [&v1, =]() {};
	auto a4 = [=, v2]() {};

}
