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

// g++ 家胶颇老.cpp - S			家胶颇老.s
// cl 家胶颇老.cpp /FAs			家胶颇老.asm