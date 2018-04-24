//1_casting5.cpp - 책 7 page addressof

#include <iostream>

using namespace std;


class Animal {
public:
	// 가상함수가 있으면 가상함수 테이블이 생성되고
	// 테이블의 제일위에는 자신이 어떤 클래스인지의 정보가 있다.
	// 결론 : dynamci_cast를 사용하려면 한개이상의 가상함수가 필요하다.
	// dynamic_cast는 부모*를 다시 자식*로 바꾸고 싶을때만 사용한다.
	// 런타임 오버헤드가 있음. 느려~~
	virtual ~Animal() {}
};

class Dog : public Animal
{
public:
	int color;

};

void foo(Animal *p)
{
	//p->color = 10;
	//p를 Dog*로 캐스팅한다.

	//Dog *pDog = p;		//error

	// static_cat : 컴파일 시간 캐스트 이므로 
	//				p가 실제 누구를 가리키는지 알 수 없다.

	Dog *pDog = static_cast<Dog*>(p);	// Compile OK
	cout << pDog << endl;
	//pDog->color = 10;

	//실행시간에 p가 가리키는 메모리를 조사해서 캐스팅
	Dog *pDog2 = dynamic_cast<Dog*>(p);	// 
	cout << pDog2 << endl;
}


int main()
{
	Dog		d; foo(&d);
	Animal	a; foo(&a);
}

