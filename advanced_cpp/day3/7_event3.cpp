//7_event3

#include <iostream>
using namespace std;

struct Window;

// 이벤트 번호와 함수 주소를 가진 구조체
struct AFX_MSG
{
	int messageno;
	void(Window::*hander)();		//멤버 함수 포인터
};

// 라이브러리 내부 코드
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


//wxWidget Event map 검색
// 아래 코드는 사용자 코드 입니다.
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