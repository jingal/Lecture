//5_SFINAE2 - 215 �����Դϴ�. �߿��մϴ�.
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
using namespace std;


// 1. exactly matching
// 2. template ���
// 3. ���� ����

//int foo(int a) { cout << "int" << endl; return 0; }


template<typename T> 
typename T::type foo(T a) { cout << "T " << endl; return 0; }
//typename int::type foo(int a) ...

// �Ʒ� �Լ� �ּ�ó�� �� �Լ��� ���ٴ� ����, (ġȯ���� ������ �ƴ�)
int foo(...) { cout << "..." << endl; return 0; }


int main()
{	
	foo(10);
}