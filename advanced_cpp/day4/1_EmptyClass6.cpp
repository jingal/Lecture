//1_EmptyClass6 - 73 page EBCO

#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
using namespace std;

/*
//추상적인 반복자의 개념을 타입화 합니다.
struct input_iterator_tag {};
struct output_iterator_tag {};

// 싱글리스트는 ++만 가능
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct randomaccess_iterator_tag : bidirectional_iterator_tag {};

// 각 반복자를 만드는 사람은 자신의 반복자가
// 어느 종류인지 알려 주어야 합니다.

template<typename T> class vector_iterator
{
	typedef randomaccess_iterator_tag iterator_category;
};


template<typename T> class list_iterator
{
	typedef bidirectional_iterator_tag iterator_category;

	//operator++
};
*/
template<typename IT>
void xadvance(IT& p, int N)
{
	if( is_same<typename IT::iterator_category, random_access_iterator_tag>::value )
		p = p + N;
	else
	{
		while (N--) ++pp;
	}
		

}

int main()
{

	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p1 = v.begin();
	auto p2 = s.begin();

	xadvance(p1, 5);
	//xadvance(p2, 5);		//에러의 원인
}