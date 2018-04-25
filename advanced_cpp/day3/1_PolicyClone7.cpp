// 1_PolicyClone7 - 183 page

#include <iostream>
#include <vector>
using namespace std;

// ����� ���� �޸� �Ҵ��
template<typename T> class MyAlloc
{
public:
	MyAlloc() = default;	//����Ʈ ������

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

	//��å ��ü�� ���� ����ü - 184 page NittyAlloc �ڵ�
	// MyAlloc<int>�� ������ MyAlloc<Node>�� ���� ��
	// �ְ� �ϱ� ���� ���� �Դϴ�.
	template<typename U> struct rebind
	{
		typedef MyAlloc<U> other;
	};
};

// ���� list�� ������ ���ô�.

template<typename T, typename Ax = allocator<T>>
class List
{
	struct Node
	{
		T data;
		Node *next;
		Node *prev;
	};

	//Ax ax;		// �޸� �Ҵ�� - MyAlloc<int>
				// �츮���� �ʿ��� ���� MyAlloc<Node> �Դϴ�.
	// Ax ax;
	//MyAlloc<int> ax;		//MyAlloc<Node>

	//MyAlloc<int>::rebind<Node>::other ax;		//MyAlloc<Node>
	typedef typename Ax::template rebind<Node>::other clonePolicy;
	clonePolicy ax;
	//typename Ax::template rebind<Node>::other ax;

public:
	void push_front(const T& a)
	{
		//�� ���� ��Ҹ� ���� �޸� �Ҵ��� �ʿ��մϴ�.
		// ��� �Ҵ� �ұ��?
		ax.allocate(1);
	}
};

int main()
{
	List<int, MyAlloc<int>> s;
	s.push_front(10);
}


