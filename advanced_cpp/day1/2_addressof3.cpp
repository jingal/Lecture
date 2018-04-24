//2_addressof2.cpp - å 7 page addressof
#include <iostream>
using namespace std;


class Point
{
	int x = 0;
	int y = 0;
public:
	Point* operator&() const { return 0; }	// �� �ּҸ� �˷����� ����.
};

template<typename T>
inline T* xaddressof(T& obj)
{
	/*
	return reinterpret_cast<T*>(
		&(reinterpret_cast<char&>(
			const_cast<T&>(obj))));
			*/
	// �Ʒ� �ڵ忡�� 2, 3��° ĳ������ ������
	// �ٲ𶧸� ������ ������.
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
