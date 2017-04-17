#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;
using namespace std::chrono;

///////////////////////////////////////////////////////////////////////////
//	Reference & temporary object (�ӽÿ� ����) #3
///////////////////////////////////////////////////////////////////////////

string foo()
{
	return string("foo");		//�ӽð�ü�� ����. 
}

void goo()
{
	throw string("goo");		//�ӽð�ü�� ���� ����.
}

int main()
{
	//string& s = foo();		// error. �ӽð�ü�� �����ϱ� ������ ������ ���� �߻�

	try {
		goo();
	}
	catch (string& e)			// �ӽð�ü�� ���ܷ� ���� ��� ������ ���� �� ���� (�������̽�)
	{
		cout << e << endl;
	}	
}