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
//	19�� 1. lvalue vs rvalue
///////////////////////////////////////////////////////////////////////////
//�����ڿ� lvalue


int main()
{
	int v1 = 10;
	int v2 = 20;
	int arr[5] = { 1,2,3,4,5 };

	int n = v1 + v2;

	v1 + v2 = 10;		// int temp = v1 + v2; return temp; error. +�������� ����� rvalue
	-v1 = 20;			// error. ���� ������ -�� ����� rvalue

	*arr = 10;			// ok. ���� ������ *�� �����  lvalue, 
	arr[1] = 10;		// ok. [] �������� ����� lvalue
}
