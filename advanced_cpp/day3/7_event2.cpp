//7_event2

#include <iostream>
using namespace std;

struct Window;

// �̺�Ʈ ��ȣ�� �Լ� �ּҸ� ���� ����ü
struct AFX_MSG
{
	int messageno;
	void(Window::*hander)();		//��� �Լ� ������
};

struct Window
{
	// �Ʒ� �����Լ����� �޼��� ó�� ������ ���� �迭�� ��ȯ�ؾ� �Ѵ�.
	virtual AFX_MSG* GetMessageMap() { return 0; }

	void msgLoop(int msgNo)
	{	
		AFX_MSG* arr = GetMessageMap();
		if (arr == 0) return;

		//���� �߻��� �޼����� �迭�� �ִ��� ã�´�.
		while (arr->hander != 0)
		{
			if (arr->messageno == msgNo)
			{
				void(Window::*f)() = arr->hander;
				(this->*f)();		//����Լ� ȣ��
			}

			++arr;
		}
	}	
};

struct MyWindow : public Window
{
	virtual AFX_MSG* GetMessageMap() 
	{ 
		// ó���ϰ� ���� �޼����� ������ ���� �迭�� 
		// ���� ��ȯ �մϴ�.
		typedef void (Window::*F)();

		static AFX_MSG arr[] = {
			{1, (F)&MyWindow::foo},
			{2, (F)&MyWindow::goo},
			{0, nullptr},
		};

		return arr;
	}

	void foo() { cout << "foo" << endl; }
	void goo() { cout << "goo" << endl; }
};

int main()
{
	MyWindow w;
	w.msgLoop(1);
}