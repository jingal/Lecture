//2_new3 - 103 page. generic container idioms

#include <iostream>
using namespace std;


struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b)
	{
		cout << "Point()" << endl;
	}

	//Point(const Point& p) { cout << "복사생성자" << endl; }
};

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
				//new(&buff[i]) T;		//디폴트 생성자
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

	void resize(int newsize, T value)
	{
		if (size < newsize)
		{
			// 메모리 재할당이 필요하다.
			// 일반적인 방법
			// 단점 1 : T의 디폴트 생성자가 필요하다.
			// 단점 2 : T가 객체일때 신규 버퍼의객체가
			//			자원을 할당할 필요 없다.
			//			기존 버퍼에서 복사해 오게 되므로
			//			자원없이 메모리만 할당해야 한다.
			//T *temp = new T[newsize];

			T *temp = static_cast<T*>(
							operator new(sizeof(T) * newsize));


			// 기존 버퍼 복사.
			for (int i = 0; i < size; i++)
			{
				//temp[i] = buff[i];	// 대입 연산

				//new(&temp[i]) T;				// 디폴트 생성자
				//new(&temp[i]) T(buff[i]);		// 복사 생성자.
				new(&temp[i]) T(move(buff[i]));		// move 생성자.
			}

			// 새롭게 추가된 메모리들에 대해서도 생성자 호출
			for (int i = size; i < newsize; i++)
			{
				new(&temp[i]) T(value);
			}

			//-----------------------------------------------------
			for(int i = 0; i < size; i++) 
			{
				buff[i].~T();			
			}
			operator delete (buff);
		}
	}
};

int main()
{
	Point p(0, 0);
	Vector<Point> v(10, p);	//될까?

	v.resize(20, p);
}