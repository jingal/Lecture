// 1_PolicyClone5 - 183 page

#include <iostream>
#include <vector>
using namespace std;


struct Point
{
	int x, y;

	//Point() { cout << "Point()" << endl; }
	Point(int a, int b) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// ����� ���� �޸� �Ҵ��
template<typename T> class MyAlloc
{
public:
	MyAlloc() = default;	//����Ʈ ������

	T* allocate(size_t sz)
	{
		cout << "allocate" << endl;
		return static_cast<T*> (
			operator new(sizeof(T) * sz));			
	}

	void deallocate(T* p, size_t sz)
	{
		operator delete(p);
	}

	/*
	// default �����ڸ� ����
	// consturct�� C++ 11����� "�Ϻ��� ������" ����� �ʿ��մϴ�.
	template<typename ... ARGS>
	void construct(T* p, ARGS&& ... args)
	{
		new(p) T(std::forward<ARGS>(args)...);
	}

	void destroy(T* p)
	{
		p->~T();
	}
	*/
};


int main()
{
	MyAlloc<Point> ax;		//C++ ǥ�� �޸� �Ҵ��

	Point* p = ax.allocate(10);

	for (int i = 0; i < 10; i++)
	{
		//ax.construct(&p[i]);	
		allocator_traits<MyAlloc<Point>>::
			construct(ax, &p[i], 1, 1);
	}

	for (int i = 0; i < 10; i++)
	{
		//ax.destroy(&p[i]);
		allocator_traits<MyAlloc<Point>>::
			destroy(ax, &p[i]);
	}

	ax.deallocate(p, 10);

}


