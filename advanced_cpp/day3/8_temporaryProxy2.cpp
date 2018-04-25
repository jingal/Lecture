// 8_temporaryProxy2 - 233 page
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;



class String
{
public:
	char* buff;
	int* ref;		//���� ����� ������ ������

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

	// ������ : �Լ� ȣ���� ���ʿ� �� �� ����.
	// ���� ���� : �Լ� ȣ���� ���ʿ� �� �� �ִ�. (lvalue)
	char& operator[](int idx) {
		return buff[idx];
	}
};

int main()
{
	String s1 = "hello";
	String s2 = s1;

	char c = s1[0];				// s1.operator[](0)
								// �ڿ� �и��� �ʿ�����ϴ�.
	cout << c << endl;

	s1[0] = 'x';				// �ڿ� �и��Ŀ� 'x'�� ����

	cout << s1.buff << endl;	//"xello"
	cout << s2.buff << endl;	//"hello"
}
