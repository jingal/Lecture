// 3_ExceptionSafefy (���ܾ�����) - 59 page

#include <iostream>
using namespace std;


// Exception Safety (���� ������)
// ���ܰ� �߻��ϴ��� ��� ����� �� �־�� �Ѵ�.
// �Ϻ� ���� : ���ܰ� ����. int a = 0, int* p = 0;

// ���� ���� : ���ܰ� ������ ���ܸ� ������ 
//				��ü�� ���´� ���ܹٻ� ������ ���¸� �����Ѵ�.

// �⺻���� : ���ܰ� �߻��ص� �ڿ� ������ ����.
//				������, ��ü�� ���´� �˼� ����. ����� �� ����.

template<typename T> class Stack
{
	T buff[10];
	int idx = 0;

public:
	void push(const T& a) {
		buff[idx++] = a;
	}
	/*
	T pop()
	{
		--idx;

		if (idx < 0)
			throw 1;

		return buff[idx];
	}
	*/


	// ������ ���� Ȯ���� ���¸� �����Ѵ�.
	T pop()
	{
		if (idx < 1)
			throw 1;

		--idx;
		return buff[idx];
	}

};

struct People {};

int main()
{
	Stack<People> s;

	People p;
	s.push(p);

	try
	{
		People p2 = s.pop();		// 1. s.pop() ȣ��
									// 2. People ���� ������
									//	2������ ���ܰ� ������ ��� �ɱ�?
									// ����� ������ ��ü ������
	}
	catch (...) {
		//s�� ���°� ���� ������ �����ұ�?
	}

	cout << "���α׷��� ��� ����" << endl;
	//�׷���, s�� ��� ����ص� �ɱ��?
}
