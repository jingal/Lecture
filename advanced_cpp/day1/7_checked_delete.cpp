#include <iostream>
#include <memory>
using namespace std;

//Test t;		//error

class Test;		// class forward declaration
Test *t;		//ok, ���漱���� ������ ����., 
				// incomplete obejct : ���漱�� �ִ� Ÿ���� 
				//						������
				// delete�ÿ� �Ҹ��ڰ� ȣ����� �ʴ´�.

//checked delete
void foo(Test* p)
{
	//sizeof(Test); //�������. ������ Ÿ�Ը� ũ�⸦ ���� �� �ִ�.
	//enum { type_must_be_comlete = sizeof(Test); };
	static_assert(sizeof(Test) >= 1, "error");

	delete p;

	default_delete<int> d;
}

class Test
{
public:
	Test() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl;  }
};

int main()
{
	Test *p = new Test;
	foo(p);
}