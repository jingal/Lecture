//7_event2

#include <iostream>
using namespace std;

struct Window;

// 이벤트 번호와 함수 주소를 가진 구조체
struct AFX_MSG
{
	int messageno;
	void(Window::*hander)();		//멤버 함수 포인터
};

struct Window
{
	// 아래 가상함수에서 메세지 처리 정보를 담은 배열을 반환해야 한다.
	virtual AFX_MSG* GetMessageMap() { return 0; }

	void msgLoop(int msgNo)
	{	
		AFX_MSG* arr = GetMessageMap();
		if (arr == 0) return;

		//현재 발생한 메세지가 배열에 있는지 찾는다.
		while (arr->hander != 0)
		{
			if (arr->messageno == msgNo)
			{
				void(Window::*f)() = arr->hander;
				(this->*f)();		//멤버함수 호출
			}

			++arr;
		}
	}	
};

struct MyWindow : public Window
{
	virtual AFX_MSG* GetMessageMap() 
	{ 
		// 처리하고 싶은 메세지의 정보를 담은 배열을 
		// 만들어서 반환 합니다.
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