// 1_PolicyClone6 - 183 page

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
		return static_cast<T*> (operator new(sizeof(T) * sz));
	}

	void deallocate(T* p, size_t sz)
	{
		operator delete(p);
	}

	typedef T value_type;
	//MyAlloc<Node> ax2 = ax;		//허용할까요? 말까요?
									// 우리가 만든 MyAlloc은 멤버데이터가 없습니다.
									// 오직 함수만 있습니다.
	template<typename U> MyAlloc(const MyAlloc<U>&)	{ }		
};


int main()
{
	vector<int, MyAlloc<int>> v;

	v.resize(10); //이순간 MyAlloc을 사용해서
					// 메모리 할당을 하게 됩니다.



}


