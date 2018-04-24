//1_casting2.cpp - å 7 page addressof

#include <iostream>
#include <memory>
#include <cstdio>
#include <cstring>

using namespace std;

// C++ ĳ����
// static_cast : ������ �ð� ĳ��Ʈ, ������ �ִ� Ÿ�Ը� ����
//					void* => �ٸ� Ÿ�� ���
//				standard conversion ���
//				������ �ð��� ����ǹǷ� ���� ���� ����


// reinterpret_cast : �޸��� ���ؼ�
//						������ ������ ĳ����
//						������ <-> �� ĳ����
//						�� <-> �� ĳ���� �ȵ�


int main()
{
	double d = 3;
	//int n = reinterpret_cast<double>(n);		// error

	//int* p = 10;							// error
	int* p = (int*)10;						// ok
	//int* p = static_cast<int*>(10);		// error
	int* p = reinterpret_cast<int*>(10);	// ok

	// ���� �ٸ� Ÿ�Ե� �ּҳ����� ����
	//double *p = reinterpret_cast<double*>(&n);	//ok


	//������ �ܿ� ������ ����
	int n2 = 10;
	char& c = reinterpret_cast<char&>(n2);


}


/*
int main()
{
	double d = 3;
	//int n = d;
	int n = static_cast<int>(d);				//standard conversion --> �Ͻ��� ������ ���

	int* p = static_cast<int*>(malloc(100));

	// ���� �ٸ� Ÿ���� �����͸� ĳ������ �� ����.
	// double* p2 = static_cast<double*>(&n);		// error

}*/