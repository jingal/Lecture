//2_생성자2

#include <iostream>
using namespace std;

// protected 생성자 - 
// 자신의 객체는 만들수 없지만, 
// 파생클래스의 객체는 만들 수 있게한다.
class Animal
{
protected:
	Animal() {}
};

class Dog : public Animal
{

};

int main()
{
	// 다음중 에러는?
	Animal a;	// error
	Dog d;		// ok
}