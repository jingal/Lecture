//7_event

#include <iostream>
using namespace std;

// ���� : �̺�Ʈ�� ���� ��ŭ �����Լ��� ������ ��.
//			����� Ŭ�������� 1~2���� �������ص�
//			��� Ŭ������ ��� �����Լ� ���� ��ŭ ���̺� ����.

struct Window
{
	void msgLoop()
	{
		//if(mouseClick == 1)
		onClick();
	}

	virtual void onClick() {}
};

struct MyWindow : public Window
{
	virtual void onClick() {}
};

int main()
{
	MyWindow w;
	w.msgLoop();
}