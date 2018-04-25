//3_coercion3 - 43 page

#include <iostream>
#include <list>
using namespace std;

class Animal {};

class Dog : public Animal {};

// 스마트 포인터를 생각해 봅시다.
template<typename T> struct smart_pointer
{
private:
	T* obj;

public:

	smart_pointer(T* p = 0) : obj(p) {}
	template<typename U> smart_pointer(U* p = 0) : obj(p) {}

	// 템플릿 생성자(일반화된 복사 생성자)
	template<typename U> 
	smart_pointer(const smart_pointer<U>& p)
	{
		obj = p.obj;
	}

	template<typename> friend class smart_pointer;
};

// 안드로이드/libutils/include/utils/StrongPointer.h

int main()
{
//	Dog* p1 = new Dog;
//	Animal* p2 = p1;

	smart_pointer<Dog> p1 = new Dog;
	smart_pointer<Animal> p2 = p1;

	smart_pointer<Animal> p3 = new Dog; //???

	MyAlloc<int> ax;
	MyAlloc<Node> ax2 = ax;		//허용할까요? 말까요?
								// 우리가 만든 MyAlloc은 멤버데이터가 없습니다.
								// 오직 함수만 있습니다.
}