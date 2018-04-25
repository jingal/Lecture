// 8_temporaryProxy - 233 page
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;



class String
{
	char* buff;
	int* ref;		//참조 계수를 관리할 포인터

public:
	String(const char* s)
	{
		buff = new char[strlen(s) + 1];
		strcpy(buff, s);

		ref = new int(1);
	}

	String(const String& p) 
	{
		buff = p.buff;
		ref = p.ref;

		++(*ref);
	}

	~String() {		
		cout << "~String()" << endl;
		if (--(*ref) == 0)
		{
			delete[] buff;
			delete ref;			
			cout << "~String() deleted" << endl;
		}
	}
};

int main()
{
	String s1 = "hello";
	String s2 = s1;
}

	

