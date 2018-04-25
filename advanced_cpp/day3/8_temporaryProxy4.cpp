// 8_temporaryProxy4 - 233 page

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
// bool을 제외한 타입에서 사용
template<typename T, typename Ax = allocator<T>>
class vector
{
	T* buff;
	Ax ax;

public:
	vector(int sz)
	{
		//buff = ax.allocate(sz);
		buff = new T[sz];
	}
};

// bool을 위한 부분 특수화
template<typename Ax = allocator<T>>
class vector <bool, Ax>
{
	//bool 타입을 위한 구현
public:
	BitProxy operator [](int idx)
	{

	}
};
*/

int main()
{
	//SSO: small string optimization
	// fb_string - "Modern C++ Design" 책 저자,
	//				안드레이 알렉산드레스큐
	string s = "sss";
	auto c = s[0];

	vector<int> v1(10);
	vector<bool> v2(10);

	auto n1 = v1[0];
	auto n2 = v2[0];

	bool b = v2[0];	//ok.. proxy => bool로 변환

	cout << typeid(n1).name() << endl;
	cout << typeid(n2).name() << endl;
}
