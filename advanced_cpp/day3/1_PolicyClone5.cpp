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

// 사용자 정의 메모리 할당기
template<typename T> class MyAlloc
{
public:
	MyAlloc() = default;	//디폴트 생성자

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
	// default 생성자만 받음
	// consturct는 C++ 11기술인 "완벽한 전달자" 기법이 필요합니다.
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
	MyAlloc<Point> ax;		//C++ 표준 메모리 할당기

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


