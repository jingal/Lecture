//4_참조계수2

#include <iostream>
#include <vector>
using namespace std;

class Car
{
	int m_refCount = 0;		//객체를 몇개의 포인터가 사용하는가 관리
public:
	void ref() { m_refCount++; }
	void deref() 
	{ 
		if (--m_refCount == 0) delete this;
	}

	//protected 소멸자 : 외부에서 객체를 파괴할 수 없게 할때 사용.
	//					객체를 스택에 만들 수 없다.
	//					195 페이지 아래

protected:
	~Car() { cout << "~Car" << endl; }
};

int main()
{
	Car *p1 = new Car;		//규칙 1. 객체 생성시 참조계수 증가
	p1->ref();

	Car *p2 = p1;			//규칙 2. 객체 복사시 참조계수 증가
	p2->ref();

	delete p1;

	//규칙 3. 사용후에는 참조계수 감소
	p2->deref();
	p1->deref();
}