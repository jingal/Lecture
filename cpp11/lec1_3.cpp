#include <iostream>

using namespace std;


int square(int a)
{
	return a * a;
}

double square(double a)
{
	return a*a;
}

int main()
{
	square(3);
	square(3.3);

	//printf("%p\n", &square);
	//printf("%p\n", (int(*)(int))&square);
	//printf("%p\n", static_cast<int(*)(int)>(&square));

	//auto p = square;		// error 

	int(&r1)(int) = square;

	//int(*f)(int) = &square; // ok
	int(*f)(int) = square; // ok
}
