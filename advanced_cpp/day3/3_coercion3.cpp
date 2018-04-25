//3_coercion3 - 43 page

#include <iostream>
#include <list>
using namespace std;

class Animal {};

class Dog : public Animal {};

// ����Ʈ �����͸� ������ ���ô�.
template<typename T> struct smart_pointer
{
private:
	T* obj;

public:

	smart_pointer(T* p = 0) : obj(p) {}
	template<typename U> smart_pointer(U* p = 0) : obj(p) {}

	// ���ø� ������(�Ϲ�ȭ�� ���� ������)
	template<typename U> 
	smart_pointer(const smart_pointer<U>& p)
	{
		obj = p.obj;
	}

	template<typename> friend class smart_pointer;
};

// �ȵ���̵�/libutils/include/utils/StrongPointer.h

int main()
{
//	Dog* p1 = new Dog;
//	Animal* p2 = p1;

	smart_pointer<Dog> p1 = new Dog;
	smart_pointer<Animal> p2 = p1;

	smart_pointer<Animal> p3 = new Dog; //???

	MyAlloc<int> ax;
	MyAlloc<Node> ax2 = ax;		//����ұ��? �����?
								// �츮�� ���� MyAlloc�� ��������Ͱ� �����ϴ�.
								// ���� �Լ��� �ֽ��ϴ�.
}