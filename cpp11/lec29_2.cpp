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
//	29�� 7. ���� ǥ���İ� ���� ���� ĸ��
///////////////////////////////////////////////////////////////////////////

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
}
