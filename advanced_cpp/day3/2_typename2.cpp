// 2_typename2

#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
void print(vector<int>& v)
{
	int n = v.front();
	cout << n << endl;
}*/

/*
template<typename T>
void print(vector<T>& v)
{
	T n = v.front();
	cout << n << endl;
}
*/

// list의 구혀운리
/*
template<typename T, typename Ax = allocator<T>>
class list
{
public:
	typedef T value_type; //핵심코드;
};

list<int> s = { 1,2,3 };
list<int>::value_type n;
*/

// 결론 : 템플릿으로 클래스를 만들때는 ㅇ
//			되도록 value_type을 넣는 것이 좋습니다.
//			안드로이드/libutils/include/vecotr.h
//			vector 첫번째 줄 확인해 보세요.
template<typename T>
void print(T& v)
{
	//T : list<double>
	//T::value_type => list<double>::value_type => double;
	typename T::value_type n = v.front();
	cout << n << endl;
}

int main()
{
	//vector<int> v = { 1,2,3 };
	//vector<double> v = { 1,2,3 };
	list<double>  v = { 1,2,3 };
	print(v);
}
	


