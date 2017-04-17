#include <iostream>
#include <cstdio>

using namespace std;

// Safe bool Idioms ==> ��ȯ�� ���輺

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

	//mycin << n;								// error; �Ͻ��� ��ȯ �ȵ�

	if (mycin)								// explicit ��ȯ �����ڰ� �־ bool�� ��ȯ ����.
	{

	}

	for (; mycin;) {}

	string s = "hello";
	char s2[10];

	strcpy(s2, s);		//error... string => const char *�� ��ȯ �ȵ�
	strcpy(s2, s.c_str());	//OK
}
