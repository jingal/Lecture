// 1_PolicyClone7 - 183 page

#include <iostream>
#include <vector>
using namespace std;

// 사용자 정의 메모리 할당기
template<typename T> class MyAlloc
{
public:
	MyAlloc() = default;	//디폴트 생성자

	T* allocate(size_t sz)
	{
		cout << "allocate" << endl;
		return static_cast<T*> (operator new(sizeof(T) * sz));
	}

	void deallocate(T* p, size_t sz)
	{
		operator delete(p);
	}

	typedef T value_type;
	template<typename U> MyAlloc(const MyAlloc<U>&) { }

	//정책 교체를 위한 구조체 - 184 page NittyAlloc 코드
	// MyAlloc<int>를 가지고 MyAlloc<Node>를 만들 수
	// 있게 하기 위한 도구 입니다.
	template<typename U> struct rebind
	{
		typedef MyAlloc<U> other;
	};
};

// 이제 list를 생각해 봅시다.

template<typename T, typename Ax = allocator<T>>
class List
{
	struct Node
	{
		T data;
		Node *next;
		Node *prev;
	};

	//Ax ax;		// 메모리 할당기 - MyAlloc<int>
				// 우리한테 필요한 것은 MyAlloc<Node> 입니다.
	// Ax ax;
	//MyAlloc<int> ax;		//MyAlloc<Node>

	//MyAlloc<int>::rebind<Node>::other ax;		//MyAlloc<Node>
	typedef typename Ax::template rebind<Node>::other clonePolicy;
	clonePolicy ax;
	//typename Ax::template rebind<Node>::other ax;

public:
	void push_front(const T& a)
	{
		//한 개의 요소를 위한 메모리 할당이 필요합니다.
		// 어떻게 할당 할까요?
		ax.allocate(1);
	}
};

int main()
{
	List<int, MyAlloc<int>> s;
	s.push_front(10);
}


