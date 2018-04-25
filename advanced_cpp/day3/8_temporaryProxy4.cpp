// 8_temporaryProxy4 - 233 page

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
// bool�� ������ Ÿ�Կ��� ���
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

// bool�� ���� �κ� Ư��ȭ
template<typename Ax = allocator<T>>
class vector <bool, Ax>
{
	//bool Ÿ���� ���� ����
public:
	BitProxy operator [](int idx)
	{

	}
};
*/

int main()
{
	//SSO: small string optimization
	// fb_string - "Modern C++ Design" å ����,
	//				�ȵ巹�� �˷���巹��ť
	string s = "sss";
	auto c = s[0];

	vector<int> v1(10);
	vector<bool> v2(10);

	auto n1 = v1[0];
	auto n2 = v2[0];

	bool b = v2[0];	//ok.. proxy => bool�� ��ȯ

	cout << typeid(n1).name() << endl;
	cout << typeid(n2).name() << endl;
}
