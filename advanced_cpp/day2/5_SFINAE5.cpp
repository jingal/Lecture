//5_SFINAE5
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
#include <type_traits>
using namespace std;

struct Shape
{
	virtual void Draw() = 0;
};

//핵심. 1. 조사할 조건에 따라 치환 실패가 되는 함수를 만든다.
//		2. 가변 인자 버전을 만들고 반환타입을 다르게 한다.

// Step 1. 문제점 : mainㅇ서 Shape를 만들 수 없다.
/*
//템플릿 버전 : 추상이 아닐때 사용
template<typename T> char check(T t);

//... : 추상일 경우 사용
short check(...);

int main()
{
	Shape s;
	check(s);
}
*/

/*
// Step 2. 문제점 : mainㅇ서 Shape를 만들 수 없다.
//템플릿 버전 : T가 추상이 아닐때 사용
// 조건 : 추상일때 실패해야 한다. main에서 인자를 보낼 수 있어야 한다.
// Shape : 추상일 때 실패, main에서 인자 보낼수 없다.
// Shape* : 추상일 때 성공...
// Shape(*)[1] : 추상일때 실패. 포인터 이므로 0전달 가능

// 인자로 0을 보낼 수 있지만, 0으로 T가 추론 안되므로
// 명시적으로 타입을 지정해야 한다.
template<typename T> char check(T (*p)[1]);

//... : 추상일 경우 사용
short check(...);

int main()
{
	//Shape s;	//error
	//Shape* p;	// ok
	//Shape(*p)[1]; //배열을 가르키는 포인터, 추상일때 error

	// 아래 코드는 무조건 check가 템플릿 버전이어야 한다.
	cout << sizeof(check<Shape>(0)) << endl;
}
*/


// Step 3. 

template<typename T> char check(T (*p)[1]);
template<typename T> short check(...);

int main()
{
// 아래 코드는 무조건 check가 템플릿 버전이어야 한다.
// 가변 인자 버전도 template으로 
cout << sizeof(check<Shape>(0)) << endl;
}
