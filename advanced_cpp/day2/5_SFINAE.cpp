//5_SFINAE - 215 page


struct A
{
	//static int DWORD;
	typedef int DWORD;
};
int p = 0;

template<typename T>
void foo(T a)
{
	// A::DWORD
	// 클래스이름::static 멤버 변수
	typename T::DWORD* p;			//DWORD 타입으로 해석해 달라.
									//T다음에 오는 것을 타입으로 해석해 달라.

	//T::DWORD* p;					//이 한줄 해석해 보세요
									// DWORD가 뭘까요

	// 1. 값 : DWORD가 static 변수인데 곱하기 p하고 있다.
	// 2. 타입 : DWORD는 내포 타입인데 포인터 변수 p를 선언
}

int main()
{
	A a;
	foo(a);
}