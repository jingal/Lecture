//1_������8

#include <iostream>
using namespace std;


//�ذ�å 2. RAII ( Resource Acquistion Is Initialize)
//			�ڿ��� ȹ���ϴ� ���� �ڿ� ������ü�� �ʱ�ȭ �ɶ��̴�.
//			�ڿ����� ���� Ŭ���� ���

// ����� �����ڰ� �����ϸ� ����� �Ҹ��ڰ� ȣ��Ǵ� ����
// ����ȴ�.

// �Ʒ� �ڵ忡�� Test �����ڴ� �����ؼ� Test �Ҹ��ڰ�
// ȣ����� ������
// p�� ������ �����ϸ� p�� �Ҹ��ڴ� ȣ��ȴ�.

// Ŭ������ �����ڿ��� �ڿ��� �Ҵ��ϸ�
// Rule of 3 : �Ҹ���, ���� ������, ���� �����ڸ� ������ �Ѵ�.
// Rule of 5 : C++11������ move ������, move ������ �ʿ��ϴ�.
// Rule of 0 : ����Ʈ �����͵��� �ڿ� ���� ������ ����ϸ� 
//			   5���� �Լ��� ������ �ʾƵ� �ȴ�.

#include <memory>

struct Test
{
	//int* p;
	shared_ptr<int> p;

	Test() : p (new int)
	{		
		//p = make_shared<int>();
		// �۾��߿��� ���� �߻�
		throw 1;
	}

};

int main()
{
	try {
		Test t;
	}
	catch (...) {}

	cout << "��� ����" << endl;

	//Test t;
}