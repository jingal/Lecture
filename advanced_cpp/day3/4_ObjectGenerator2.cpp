// 4_ObejctGennerator2 - 177 page

//#include <iostream>
//using namespace std;

template<typename T, typename U>		//178 ���� �� �ҽ�
struct pair
{
	T first;
	U second;
	pair(T a, U b) : first(a), second(b) {}
};

//pair�� ����� �Լ��� ��������.

template<typename T, typename U>
pair<T, U> make_pair(T a, U b)
{
	return pair<T, U>(a, b);
}

int main()
{
	// �Ʒ� �ڵ带 ���� ���ϰ� ����� �� ���� ���?
	pair<int, double> p1(1, 3.4);

	//make_pair<int, double> (1, 3.4);
	// auto : �캯�� ������ Ÿ������ �ش޶�� ���þ�.
	auto p2 = make_pair(1, 3.4);

	foo( pair ������ �ʹ�.)
}


