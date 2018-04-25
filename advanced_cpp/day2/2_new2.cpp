//2_new2 - 103 page. generic container idioms

#include <iostream>
using namespace std;


struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) 
	{
		cout << "Point()" << endl;
	}
};

// T의 조건 : 복사 생성자만 있으면 Vector 사용 가능
template<typename T> class Vector
{
	T*  buff;
	int size;

public:
	Vector(int sz, T value = T())
	{
		size = sz;
		buff = static_cast<T*>(
					operator new(sizeof(T) * sz));

		int i = 0;
		try {		
			for (; i < sz; i++)
			{
				//new(&buff[i]) T;		//디폴트 생성자, 시험
				new(&buff[i]) T(value);		//디폴트 생성자
			}
		}
		catch (...) {
			//예외가 발생한 경우 생성자 호출에 성공한
			// 객체까지 소멸자를 호출하고 메모리 해지
			for (int j = i - 1; j <= 0; j--)
			{
				buff[j].~T();
			}

			operator delete(buff);
		}
	}
};

int main()
{
	Point p(0, 0);
	Vector<Point> v(10, p);	//될까?
}