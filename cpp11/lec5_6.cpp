#include <iostream>
#include <cstdio>

using namespace std;

// Safe bool Idioms ==> 변환의 위험성

//void dummy_function() {}
class myistream
{
public:
	bool fail() { return false; }
	void operator>> (int n) {}

	// C++ 11
	explicit operator bool() { return !fail(); }
};

myistream mycin;

int main()
{
	int n = 0;
	mycin >> n;

	//bool b1 = mycin;						//implicit conversion
	bool b2 = static_cast<bool>(mycin);		//explicit conversion
	bool b3(mycin);							//ok..

	//mycin << n;								// error; 암시적 변환 안됨

	if (mycin)								// explicit 변환 연산자가 있어도 bool로 변환 가능.
	{

	}

	for (; mycin;) {}

	string s = "hello";
	char s2[10];

	strcpy(s2, s);		//error... string => const char *로 변환 안됨
	strcpy(s2, s.c_str());	//OK
}
