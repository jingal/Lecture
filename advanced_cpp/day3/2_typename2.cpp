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

// list�� �����
/*
template<typename T, typename Ax = allocator<T>>
class list
{
public:
	typedef T value_type; //�ٽ��ڵ�;
};

list<int> s = { 1,2,3 };
list<int>::value_type n;
*/

// ��� : ���ø����� Ŭ������ ���鶧�� ��
//			�ǵ��� value_type�� �ִ� ���� �����ϴ�.
//			�ȵ���̵�/libutils/include/vecotr.h
//			vector ù��° �� Ȯ���� ������.
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
	


