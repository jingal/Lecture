#include <iostream>
#include <string>
//#include <second>

using namespace std;


void foo(string s) {}
void foo(const char *s) {}

int main()
{
	int n1 = 0b10; //2Áø¼ö
	int n2 = 1'000'000;

	int x[10] = { 1,2,3,4,5,6,7,8,9.10 };

	auto n3 = x[0];
	decltype(n3) n4 = n3;

	for (int i = 0; i < 10; i++)
		cout << x[i] << endl;

	for (int n5 : x) // range for
		cout << n5 << endl;

	foo("hello");	//const char*
	foo("hello"s);	// string

	seconds s = 3min + 20s;

	cout << s.
		
}