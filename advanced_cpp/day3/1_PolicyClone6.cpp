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
	//MyAlloc<Node> ax2 = ax;		//����ұ��? �����?
									// �츮�� ���� MyAlloc�� ��������Ͱ� �����ϴ�.
									// ���� �Լ��� �ֽ��ϴ�.
	template<typename U> MyAlloc(const MyAlloc<U>&)	{ }		
};


int main()
{
	vector<int, MyAlloc<int>> v;

	v.resize(10); //�̼��� MyAlloc�� ����ؼ�
					// �޸� �Ҵ��� �ϰ� �˴ϴ�.



}


