// 4_ObejctGennerator2 - 177 page

//#include <iostream>
//using namespace std;

template<typename T, typename U>		//178 제일 위 소스
struct pair
{
	T first;
	U second;
	pair(T a, U b) : first(a), second(b) {}
};

//pair를 만드는 함수를 제공하자.

template<typename T, typename U>
pair<T, U> make_pair(T a, U b)
{
	return pair<T, U>(a, b);
}

int main()
{
	// 아래 코드를 좀더 편하게 사용할 수 없을 까요?
	pair<int, double> p1(1, 3.4);

	//make_pair<int, double> (1, 3.4);
	// auto : 우변과 동일한 타입으로 해달라는 지시어.
	auto p2 = make_pair(1, 3.4);

	foo( pair 보내고 싶다.)
}


