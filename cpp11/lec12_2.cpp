#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	member initialization
///////////////////////////////////////////////////////////////////////////

int x = 0;

class Test
{
public:
	//int data = 0;		//member initializer
	int data = ++x;		//이전에는 먼저 실행 되고 생성자 불림
						//11부터는 초기화 코드가 있을 경우, 생성자 먼저 불림

	Test() {}
	Test(int b) : data(b) {}		// 초기화 리스트가 있을 경우 멤버 초기화 코드 실행안됨
};

int main()
{
	Test t1;					//t1.data => 1
	Test t2(3);					//t2.data => 3

	cout << t1.data << endl;	//0
	cout << t2.data << endl;	//3

	char c1{ 0 };
	char c2 = { 0 };
	char c3 = { 'a' };
	char c4 = { 300 };
}