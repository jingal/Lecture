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

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	26�� ���� ǥ���� �Ұ� (Lambda Expression)
///////////////////////////////////////////////////////////////////////////

int main()
{
	auto f = [](int a, int b) {return a + b; };
	cout << f(1, 2) << endl;
}
