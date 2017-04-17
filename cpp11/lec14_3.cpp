#include <iostream>
#include <type_traits>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	decltype
///////////////////////////////////////////////////////////////////////////

int main()
{
	int n = 10;

	const int& r = n;

	decltype(r) r2 = r;		//const int& r2;

//	cout << type_id_with_cvr<decltype(r2)>().pretty_name() << endl;
}

