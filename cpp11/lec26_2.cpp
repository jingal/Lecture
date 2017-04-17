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
//	26�� �Լ� ��ü(Function Object, Functor)
///////////////////////////////////////////////////////////////////////////

//�Լ���ü : ()�� ����ؼ� ȣ�Ⱑ���� ��� ��ü
//			�Ϲ��Լ�, �Լ� ������, �Լ��� ���� ����, ����Լ�, ����Լ� ������, ����
//			()�����ڸ� �������� ��ü

class Plus
{
public:
	int operator()(int a, int b) const
	{
		return a + b;
	}
};


int main()
{
	Plus p; //p�� ��ü

	int n = p(1 , 2);	// p.operator() (1,2)


	// a+b => a.operator+ (b)
	// a-b => a.operator- (b)
	// a() => a.operator() ()
	// a(1,2) => a.operator() (1,2)
}
