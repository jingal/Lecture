//7_event3

#include <iostream>
using namespace std;

struct Window;

// �̺�Ʈ ��ȣ�� �Լ� �ּҸ� ���� ����ü
struct AFX_MSG
{
	int messageno;
	void(Window::*hander)();		//��� �Լ� ������
};

// ���̺귯�� ���� �ڵ�
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

#define DECLARE_EVENT_MAP()	\
	virtual AFX_MSG* GetMessageMap();


#define BEGIN_EVENT_MAP(classname)	\
	AFX_MSG* classname::GetMessageMap()	\
	{								\
		typedef void (Window::*F)();\
		static AFX_MSG arr[] = {	\

typedef void (Window::*F)();
#define EVENT_MAP(message,function)	\
	{ message, (F)function },

#define END_EVENT_MAP()			\
			{ 0, 0},			\
		};						\
		return arr;				\
	}


//wxWidget Event map �˻�
// �Ʒ� �ڵ�� ����� �ڵ� �Դϴ�.
struct MyWindow : public Window
{
	DECLARE_EVENT_MAP()
	void foo() { cout << "foo" << endl; }
	void goo() { cout << "goo" << endl; }
};

BEGIN_EVENT_MAP(MyWindow)
	EVENT_MAP(1, &MyWindow::foo)
	EVENT_MAP(2, &MyWindow::goo)
END_EVENT_MAP()


int main()
{
	MyWindow w;
	w.msgLoop(1);
}