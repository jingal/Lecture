#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	braced init
///////////////////////////////////////////////////////////////////////////

// 일관된 초기화 (uniform initialize, brace init) : 객체의 형태에 상관 없이 중괄호(brace, {}) 를 사용해서 초기화 하는것.

// prevent narrow : 데이터 손실이 발생하는 초기화는 error 발생

// braced-init-list

int main()
{
	int n1 = { 0 };
	int n1 = { 3.4 };
	char n1 = { 300 };


	int x[3] = { 1,2,3 };

	vector<int> v = { 1,2,3 };
}
