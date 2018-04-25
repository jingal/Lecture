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

	// ����� ������ �ִٸ� ���ο� ��Ҹ� �߰������� 
	// �����Ѵ�.
	// primitive Ÿ�� ���ٴ� user type�� �� �� �ִ� 
	// ���� ����.
	struct Proxy
	{
		String& str;
		int idx;

		Proxy(String& s, int i) : str(s), idx(i) {}

		// Proxy -> char���� �Ͻ��� ��ȯ ���
		// ��ȯ ������ �Լ�
		// Proxy�� �����ʿ� ���� ��
		operator const char&() const
		{
			cout << "read, buff �и� �ʿ����" << endl;
			return str.buff[idx];
		}

		// Proxy�� lvalue �϶�		
		Proxy& operator=(const char& c)
		{
			cout << "write, buff �и��ؾ� �Ѵ�." << endl;
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
								// �ڿ� �и��� �ʿ�����ϴ�.
	cout << c << endl;

	s1[0] = 'x';				// �ڿ� �и��Ŀ� 'x'�� ����

	cout << s1.buff << endl;	//"xello"
	cout << s2.buff << endl;	//"hello"
}
