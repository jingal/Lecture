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
//	29�� 9. ���� ĸ�� ���� ����
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
	delete p;		//��ü�ı�

	f(5);			// this->data = 5;
}

/*
���� 1��

int main()
{
	function<void(int)> f;

	{
		int v = 10;			//f���� ������ v�� �ı���
		f = [&v](int a) {v = a; };
	}

	f(5);
}
*/