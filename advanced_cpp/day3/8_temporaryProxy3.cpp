// 8_temporaryProxy3 - 233 page
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;



class String
{
public:
	char* buff;
	int* ref;

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

	// 어려운 문제가 있다면 새로운 요소를 중간층으로 
	// 도입한다.
	// primitive 타입 보다는 user type이 할 수 있는 
	// 일이 많다.
	struct Proxy
	{
		String& str;
		int idx;

		Proxy(String& s, int i) : str(s), idx(i) {}

		// Proxy -> char로의 암시적 변환 허용
		// 변환 연산자 함수
		// Proxy가 오른쪽에 있을 때
		operator const char&() const
		{
			cout << "read, buff 분리 필요없다" << endl;
			return str.buff[idx];
		}

		// Proxy가 lvalue 일때		
		Proxy& operator=(const char& c)
		{
			cout << "write, buff 분리해야 한다." << endl;
			if (*(str.ref) > 1)
			{
				char* temp = new char[strlen(str.buff) + 1];
				strcpy(temp, str.buff);
				str.buff = temp;
			}

			str.buff[idx] = c;
			return *this;
		}
	};

	Proxy operator[](int idx) {
		return Proxy(*this, idx);
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
