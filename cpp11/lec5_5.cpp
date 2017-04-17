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
	
	//1. bool�� ��ȯ����.
	//operator bool() { return !fail(); }

	//2. ����Ʈ ������ �ȵǴ� Ÿ������ ��ȯ����. --> �����ͷ� ��ȯ����
	//operator void*() { return fail() ? 0 : this; }


	//3. delete�� ���� �ʴ� �����͸� �������.
	// �Լ� ������
	//typedef void(*PF)();
	//operator PF() { return fail() ? 0 : &dummy_function; }

	//4. ����Լ� �����ͷ��� ��ȯ.. ���ۿ��� c++ idioms, �ν�Ʈ�� trybool�� ����ϴ� ���
	void dummy_function() {}
	typedef void(myistream::*PF)();
	operator PF() { return fail() ? 0 : &myistream::dummy_function; }
};

myistream mycin;

int main()
{
	int n = 0;
	mycin >> n;

	if (mycin) 
	{

	}

	//mycin << n;		//error�� �߻����� ����, bool ��ȯ�� �Ǳ� ������ bool�� �ǰ� ����Ʈ ������ �ع����� ��

	//delete mycin;		// C++ 98���� delete cin�� ������ ������ ����..

	void(*f)() = mycin;	//ok..
}



/*
int main()
{
	int n = 0;

	cin >> n;		//'a'

	if (cin.fail())
	{
		cout << "�Է� ����.." << endl;
	}

	if (cin)	// if (bool, ����, �Ǽ�, ������) , ������ ��ü�� if���� �� �� �ִ� ����
				//									c++98���� : cin.operator void*()
	{
		cout << "�Է� ����.." << endl;
	}
}
*/