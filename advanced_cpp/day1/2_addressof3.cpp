//2_addressof2.cpp - 책 7 page addressof
#include <iostream>
using namespace std;


class Point
{
	int x = 0;
	int y = 0;
public:
	Point* operator&() const { return 0; }	// 내 주소를 알려하지 말라.
};

template<typename T>
inline T* xaddressof(T& obj)
{
	/*
	return reinterpret_cast<T*>(
		&(reinterpret_cast<char&>(
			const_cast<T&>(obj))));
			*/
	// 아래 코드에서 2, 3번째 캐스팅의 순서가
	// 바뀔때를 생각해 보세요.
	return reinterpret_cast<T*>(
			&(const_cast<char&>(
				(reinterpret_cast<const volatile char&>(obj)))));
}

/*
template<typename T>
inline const T* xaddressof(const T& obj)
{A
	return reinterpret_cast<T*>(
		&(reinterpret_cast<char&>(
			const_cast<T&>(obj))));
}
*/

int main()
{
	Point pt1;
	const Point pt2;

	Point* p1 = xaddressof(pt1);
	const Point* p2 = xaddressof(pt2);

	cout << p1 << endl;
	cout << p2 << endl;
}
