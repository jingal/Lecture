// 3_ExceptionSafefy4 (예외안정성) - 59 page

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//copy and swap 개념

class String
{
	char* buff;

public:
	String(const char* s) {
		buff = new char[strlen(s) + 1];
		strcpy(buff, s);
	}

	//= 연산자를 만들어 봅시다.
	// 아래 코드는 예외 안정성을 만족할 수 없습니다.
	String& operator=(const String& s) 
	{
		if (&s == this) return *this;
		//String temp(s);		//책 내용 - 복사 생성자 필요

		String temp(s.buff);		//copy

		swap(temp);					// swap
		return *this;
	}

	// swap에는 절때 예외가 없어야 한다.
	void swap(String& s) noexcept
	{
		std::swap(buff, s.buff);
	}
};


int main()
{
	String s1 = "hello";
	String s2 = "a";
	s2 = s1;
}
