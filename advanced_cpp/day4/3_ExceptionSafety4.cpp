// 3_ExceptionSafefy4 (���ܾ�����) - 59 page

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//copy and swap ����

class String
{
	char* buff;

public:
	String(const char* s) {
		buff = new char[strlen(s) + 1];
		strcpy(buff, s);
	}

	//= �����ڸ� ����� ���ô�.
	// �Ʒ� �ڵ�� ���� �������� ������ �� �����ϴ�.
	String& operator=(const String& s) 
	{
		if (&s == this) return *this;
		//String temp(s);		//å ���� - ���� ������ �ʿ�

		String temp(s.buff);		//copy

		swap(temp);					// swap
		return *this;
	}

	// swap���� ���� ���ܰ� ����� �Ѵ�.
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
