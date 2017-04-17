#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>
#include <memory>
#include <functional>
#include <thread>
#include <ctime>
#include <algorithm>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	27강 함수 객체의 장점 #2 - 성능
///////////////////////////////////////////////////////////////////////////

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less { inline bool operator()(int a, int b) { return a < b; } };
struct Greator { inline bool operator()(int a, int b) { return a > b; } };


int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// STL의 sort()의 모든 인자는 template입니다.

	// 1. 비교 정책으로 일반함수를 사용할 때
	// 장점 : 정책을 여러번 교체해도 sort()함수가 하나이다.
	// 단점 : 정책의 인라인 치환이 안된다.

	sort(x, x + 10, cmp1);		// sort(int*, int*, bool(*)(int, int)) 인 함수 생성
	sort(x, x + 10, cmp2);		// sort(int*, int*, bool(*)(int, int)) 인 함수 생성


	// 2. 비교 정책으로 함수객체를 사용할 때
	// 장점 : 정책의 인라인 치환이 가능.
	// 단점 : 비교정책을 교체한 횟수만큼 sort()생성

	Less f1;
	Greator f2;

	sort(x, x + 10, f1);		// sort(int*, int*, Less) 인 함수 생성
	sort(x, x + 10, f2);		// sort(int*, int*, Greator) 인 함수 생성


}
