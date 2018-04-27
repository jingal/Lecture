//1_auto4

#include <iostream>
#include <list>
using namespace std;

template<typename T> class Vector
{
public:
	Vector() {}
	Vector(int sz, T value) {}

	template<typename IT> // IT는 반복자
	Vector(IT first, IT second) {}
};

// template type deduction guide
Vector()->Vector<int>;		// 이 경우는 좋은 코드는 아닙니다.
							// 그냥 에러가 나오게 하는게 좋습니다.

//template<typename IT>
//Vector(IT first, IT second)->Vector<remove_reference<decltype(*)>::type>;

//Vector(IT, IT)->Vector<remove_reference<typename IT::value_type>;

Vector(IT, IT)->Vector<remove_reference<
			typename iterator_traits<IT>::value_type>;

int main()
{
	Vector<int> v(10, 1);		//until C++17
	Vector v(10, 1);			//C++17 부터 int 생략 가능
	Vector v2;					//

	list<int> s = { 1,2,3 };

	Vector v3(s.begin(), s.end());

	int x[3] = { 1,2,3 };
	Vector v4(x, x + 3);
}