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
//	27�� �Լ� ��ü�� ���� #2 - ����
///////////////////////////////////////////////////////////////////////////

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less { inline bool operator()(int a, int b) { return a < b; } };
struct Greator { inline bool operator()(int a, int b) { return a > b; } };


int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// STL�� sort()�� ��� ���ڴ� template�Դϴ�.

	// 1. �� ��å���� �Ϲ��Լ��� ����� ��
	// ���� : ��å�� ������ ��ü�ص� sort()�Լ��� �ϳ��̴�.
	// ���� : ��å�� �ζ��� ġȯ�� �ȵȴ�.

	sort(x, x + 10, cmp1);		// sort(int*, int*, bool(*)(int, int)) �� �Լ� ����
	sort(x, x + 10, cmp2);		// sort(int*, int*, bool(*)(int, int)) �� �Լ� ����


	// 2. �� ��å���� �Լ���ü�� ����� ��
	// ���� : ��å�� �ζ��� ġȯ�� ����.
	// ���� : ����å�� ��ü�� Ƚ����ŭ sort()����

	Less f1;
	Greator f2;

	sort(x, x + 10, f1);		// sort(int*, int*, Less) �� �Լ� ����
	sort(x, x + 10, f2);		// sort(int*, int*, Greator) �� �Լ� ����


}
