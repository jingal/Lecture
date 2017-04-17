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


	//auto f1 = [](int a) {return a + v1; };		//error

	//auto f1 = [v1](int a) {return a + v1; };			//ok
	//auto f2 = [v1, v2](int a) {return a + v1; };		//ok

	// �Ϲ� ���� : ()������ �Լ��� ����� �ȴ�.
	//auto f3 = [=](int a) {return a + v1; };				// ��� ���� ���� ĸ��


	// mutable ���� : () ������ �Լ��� ���� �Լ��� �ȴ�.
	auto f4 = [=](int a) mutable {v1 = 10;  return a + v1 + v2; };				// error. v1�� read�� ����..

	f4(10);		//v1 = 10�� ����ȴ�.... ��� data v1�� ����ȴ�.

	cout << v1 << endl;		//0

	/*
	class Closure
	{
		int v1;
		int v2;

	public:
		Closure(int a, int b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			// ��� �Լ��̱� ������ ��������� ������ �� ����
			v1 = 10;
			return a + v1 + v2;
		}
	};

	//���� ������ Ŭ���� ��ü�� ����
	auto f1 = Closure(v1, v2);
	*/
}


/*
// ��������

int g = 0;

int main()
{
	auto f1 = [](int a) {g = 10; return g + a; };	//ok.. ���������� ������ ���ٰ���. R/W ��� ����. 

	cout << f1(5) << endl;

	cout << g << endl;
}
*/