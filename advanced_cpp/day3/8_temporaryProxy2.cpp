// 8_temporaryProxy2 - 233 page
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;



class String
{
public:
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

	~String() 
	{		
		if (--(*ref) == 0)
		{
			delete[] buff;
			delete ref;			
		}
	}

	// 값리턴 : 함수 호출이 왼쪽에 올 수 없다.
	// 참조 리턴 : 함수 호출이 왼쪽에 올 수 있다. (lvalue)
	char& operator[](int idx) {
		return buff[idx];
	}
};

int main()
{
	String s1 = "hello";
	String s2 = s1;

	char c = s1[0];				// s1.operator[](0)
								// 자원 분리할 필요없습니다.
	cout << c << endl;

	s1[0] = 'x';				// 자원 분리후에 'x'로 변경

	cout << s1.buff << endl;	//"xello"
	cout << s2.buff << endl;	//"hello"
}
