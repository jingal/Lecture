#include <iostream>
#include <string>

using namespace std;

int square(int a)
{
	return a * a;
}

int square(double a)
{
	return a * a;
}

int main()
{
	square(3);
	square(3.3);
}

// g++ �ҽ�����.cpp - S			�ҽ�����.s
// cl �ҽ�����.cpp /FAs			�ҽ�����.asm