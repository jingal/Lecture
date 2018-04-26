// 3_ExceptionSafefy2 (���ܾ�����) - 59 page

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

int main()
{
	Stack<int> s;

	try {
		s.pop();
	}
	catch (...) {}

	cout << "���α׷��� ��� ����" << endl;
	//�׷���, s�� ��� ����ص� �ɱ��?
}
